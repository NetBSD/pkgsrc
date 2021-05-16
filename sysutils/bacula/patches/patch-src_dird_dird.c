$NetBSD: patch-src_dird_dird.c,v 1.1 2021/05/16 06:56:31 jnemeth Exp $

Upstream bug #2551:

I noticed that the command "show catalog" is truncating the name of db_driver

======================================
*show catalog
Catalog: name=MyCatalog address=localhost DBport=5432 db_name=bacula
      db_driver=PostgreSQ db_user=bacula MutliDBConn=0
*
======================================

Turns out that the bug is more than just a display problem
(from the bacula-devel mailing list):

To: bacula-devel@lists.sourceforge.net
Message-ID: <c2515e90-0bf3-bc5e-1908-e7b23867b17a@baculasystems.com>
Date: Wed, 20 Jan 2021 13:22:19 +0100
Subject: Re: [Bacula-devel] Something amiss in bacula-9.6.7: Possible race
 condition
List-Id: Developer's email list <bacula-devel.lists.sourceforge.net>
List-Archive: <http://sourceforge.net/mailarchive/forum.php?forum_name=bacula-de
vel>
From: Eric Bollengier via Bacula-devel <bacula-devel@lists.sourceforge.net>

Hello Martin,

Very good detective work, this subtle issue was causing concurrent
database access even if the batch mode was disabled. I have pushed the
patch into the Branch-9.6 git repository.

Best Regards,
Eric

> What is the output of "show catalog" in bconsole?  My guess is that you will
> see db_driver=MySQ i.e. missing the final "L" of MySQL.  This will prevent it
> from reusing the BDB object, leading to unexpected concurrency.
>
> The bug is caused by this change:
>
> diff --git a/bacula/src/dird/dird.c b/bacula/src/dird/dird.c
> index fdb1d97bf9..11c4406ea7 100644
> --- a/bacula/src/dird/dird.c
> +++ b/bacula/src/dird/dird.c
> @@ -1265,7 +1265,7 @@ static bool check_catalog(cat_op mode)
>             /* To copy dbdriver field into "CAT" catalog resource class (local
)
>              * from dbdriver in "BDB" catalog DB Interface class (global)
>              */
> -            strncpy(catalog->db_driver, BDB_db_driver, db_driver_len);
> +            bstrncpy(catalog->db_driver, BDB_db_driver, db_driver_len);
>           }
>        }
>
> which was part of 9.6.4.
>
> To fix it, replace db_driver_len with db_driver_len+1 in this call to
> bstrncpy.  This has been fixed in Bacula 11 because the seemingly minor
> problem with "status catalog" was reported in
> https://bugs.bacula.org/view.php?id=2551 but it looks like the significance of
> it wasn't realized.


--- src/dird/dird.c.orig	2020-12-10 13:26:39.000000000 +0000
+++ src/dird/dird.c
@@ -1265,7 +1265,7 @@ static bool check_catalog(cat_op mode)
            /* To copy dbdriver field into "CAT" catalog resource class (local)
             * from dbdriver in "BDB" catalog DB Interface class (global)
             */
-            bstrncpy(catalog->db_driver, BDB_db_driver, db_driver_len);
+            bstrncpy(catalog->db_driver, BDB_db_driver, db_driver_len + 1);
          }
       }
 
