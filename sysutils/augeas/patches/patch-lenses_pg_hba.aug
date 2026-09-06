$NetBSD: patch-lenses_pg_hba.aug,v 1.1 2026/09/06 18:44:01 bsiegert Exp $

Add the /usr/local paths, which are missing from three filters.

/usr/local/pgsql/data is what PostgreSQL itself uses by default, on any
operating system, when built from source with the default prefix.  The
filter carries the Red Hat and Debian layouts but not that one.

Sent upstream as hercules-team/augeas#888; this is that diff.

--- lenses/pg_hba.aug.orig
+++ lenses/pg_hba.aug
@@ -81,6 +81,7 @@ module Pg_Hba =
     (* View: filter
         The pg_hba.conf conf file *)
     let filter = (incl "/var/lib/pgsql/data/pg_hba.conf" .
+                  incl "/usr/local/pgsql/data/pg_hba.conf" .
                   incl "/var/lib/pgsql/*/data/pg_hba.conf" .
                   incl "/var/lib/postgresql/*/data/pg_hba.conf" .
                   incl "/etc/postgresql/*/*/pg_hba.conf" )
