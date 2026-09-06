$NetBSD: patch-lenses_postgresql.aug,v 1.1 2026/09/06 18:44:01 bsiegert Exp $

Add the /usr/local paths, which are missing from three filters.

/usr/local/pgsql/data is what PostgreSQL itself uses by default, on any
operating system, when built from source with the default prefix.  The
filter carries the Red Hat and Debian layouts but not that one.

Sent upstream as hercules-team/augeas#888; this is that diff.

--- lenses/postgresql.aug.orig
+++ lenses/postgresql.aug
@@ -70,6 +70,7 @@ let lns = (Util.empty | Util.comment | entry)*
 
 (* Variable: filter *)
 let filter = (incl "/var/lib/pgsql/data/postgresql.conf" .
+              incl "/usr/local/pgsql/data/postgresql.conf" .
               incl "/var/lib/pgsql/*/data/postgresql.conf" .
               incl "/var/lib/postgresql/*/data/postgresql.conf" .
               incl "/etc/postgresql/*/*/postgresql.conf" )
