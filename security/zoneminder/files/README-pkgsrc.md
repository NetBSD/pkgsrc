===========================================================================
$NetBSD: README-pkgsrc.md,v 1.1 2022/09/27 01:20:39 gdt Exp $

Performance:

  ZoneMinder benefits dramatically from using libjpeg-turbo.  Consider
  building from Pkgsrc with:

  JPEG_DEFAULT=libjpeg-turbo


To get ZoneMinder started a MySQL database is required.

First, create a MySQL user "zmuser":

echo "create user 'zmuser'@'localhost' identified by 'zmpass';" | mysql -u root

The default password is "zmpass".  You may change this to something else, and
update ZM_DB_PASS in ${PKG_SYSCONFDIR}/zm.conf.


Create the initial database via:

  mysql -u root < ${PREFIX}/share/zoneminder/db/zm_create.sql


Assign rights to the "zmuser" user via:

  echo "grant all on * to 'zmuser';" | mysql -u root zm


Upgrade a database from an older version of ZoneMinder via:

  zmupdate.pl -u root [-p <password>]


To enable the web interface via Apache, add the following line to httpd.conf:

  Include ${PREFIX}/share/examples/zoneminder/apache/zoneminder.conf

PHP may log warnings if the PHP date.timezone configuration is not set.
Consider assigning a default system time zone to date.timezone in
${PKG_SYSCONFDIR}/php.ini.
===========================================================================
