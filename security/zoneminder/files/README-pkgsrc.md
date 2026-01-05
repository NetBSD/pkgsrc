# Introduction

This is a local pkgsrc README for the zoneminder package.  It attempts
not to duplicate the upstream documentation.  (Arguably, some of this
should be pushed upstream.)  This REAMDE presumes familiarity with
zoneminder, adminstering a web server, adminstering mysql, and
hand-typing SQL UPDATE statements.

We write /var for ${VARBASE}, /usr/pkg for ${PREFIX}, and /usr/pkg/etc
for ${PKG_SYSCONFDIR}, without loss of generality.

# Meta

This README is not really debugged.  If you think it might be wrong,
speak up.

See upstream instructions at
https://zoneminder.readthedocs.io/en/stable/installationguide/ubuntu.html
which are for Ubuntu, but seem mostly generic.

# Choice of jpeg implementation

ZoneMinder claims to benefit dramatically from using libjpeg-turbo.
Because `JPEG_DEFAULT=libjpeg-turbo` is the default setting, no action
is required.

# User and Group

zoneminder uses `APACHE_USER` and `APACHE_GROUP`.  These are www by
default, but people set them to fpm for use with nginx and php_fpm.
It is important that apache, zoneminder, and any existing directories
all agree.

See "Step 6: Set permissions", and use APACHE_GROUP.

# Choice of database

The choices are mysql and MariaDB.  While in some sense MariaDB is a
kind of mysql, p5-DBD has decided that it's not.  Thus there is a
package option to choose the database.  Pay attention to the example
config which sets `ZM_DB_TYPE` accordingly, and avoid (as always)
unintended local divergence.

# MySQL configuration and initial database creation

Add `bind-address=127.0.0.1` to `etc/my.conf` if you are using mysql
only for zoneminder and therefore do not want it accessible from the
network.  Or do the equivalent for MariaDB.

Specifically, see "Step 5: Configure the ZoneMinder Database".

The default password is "zmpass".  You should change this to something
else, and set `ZM_DB_PASS` in `/usr/pkg/etc/zm/conf.d/zmcustom.conf`.

# PHP

See "Step 9: Edit Timezone in PHP".  Otherwise, access to streams will
fail because authentication hashes will mismatch.  See
https://github.com/ZoneMinder/ZoneMinder/issues/1552 for more
information.
 
# Web setup

## apache

See "Step 7: Configure Apache correctly", but edit the apache config
file instead of using the not-in-pkgsrc a2enmod command.

mod_cgid is a hard requirement.  zm appears to work without rewrite
and expire.  headers is default on.  Enabling a zoneminder apache
module does not make sense, but upstream maybe implies that you
should.

One used to have to use prefork instead of event with cgid, because
php was built without threads.  Now, other MPMs might work.

Zoneminder installs
/usr/pkg/share/examples/zoneminder/apache/httpd-zoneminder.conf,
which does two things:
  - aliases /zm to the zm main dir and /zm/cgi-bin/ to the zm cgi directory
  - allows those paths to 127.0.0.1
Either `Include` this, copy/modify and `Include`, or insert into
httpd.conf.  (You will need to adjust the IP acl if you want
off-machine access.)

It is for future study to use www/ap2-fcgid instead of mod_cgid, and
then one could use the event MPM.

## nginx

After you figure it out, please send patches to add an nginx config
file.  Likely one would use php_fpm; Makefile guesses so.

# Problems not clearly attributed

In theory `zmpkg.pl start` should start everything.  In practice, the
first `zmdc.pl start` invocation does start the daemon but then fails
to exit, hanging the startup process.  While there is an attempt to
avoid this in `zmpkg.pl`, it is for now necessary to kill the hanging
start script and thus to write a script to do so, to enable reliable
starting.  See `start-watchdog.sh`, not yet validated.  This is likely
an upstream issue, to be debugged after pkgsrc is up to date.

# Upgrading

For upgrading from previous stable versions: as always, backup
everything, diff all configs from upstream before and minimize, save
deltas, and merge to new upstreams keeping intended changes.  This is
going to be worse than most upgrades.

For upgrading to new micros of the same stable version, of course make
backups but there is no particular reason to worry.

## Standard zoneminder advice

After installing a new zoneminder version (even a micro), upgrade a
database via:

  zmupdate.pl -u root [-p <password>]

Beware that if you have custom config in zm.conf or in the database
(because that used to be how it's done), zoneminder may migrate it
to `/usr/pkg/etc/zm/conf.d/zmcustom.conf`.

As always, make one more backup than you think you need, and check the
resulting config files.

## Zoneminder path woes

In theory, one wouldn't have to set paths, but it seems one does.
Find and read the docs and think about this.

Probably, as of 2026-01, the package mostly sets reasonable defaults
for paths.

### Storage

Zoneminder has "Storage" configured (Options, Storage), and it is
possible that it used to be /var/cache/zoneminder/events and should
now be `/var/db/zoneminder/events`.

### Upload temp dir

One can configure uploads and a temp dir in which to create them.
By default it might be `/var/db/zoneminder/upload`.

# Shared memory

Zoneminder tries to use a shm filesystem to store files that are then
mmap'd.  pkgsrc sets this to /var/shm which is right for NetBSD; it is
left for future work to set the default based on OS type.
