# Introduction

This is a local pkgsrc README for the zoneminder package.  It attempts
not to duplicate the upstream documentation.  (Arguably, some of this
should be pushed upstream.)  This REAMDE presumes familiarity with
zoneminder, adminstering a web server, adminstering mysql, and
hand-typing SQL UPDATE statements.

We write /var for ${VARBASE}, /usr/pkg for ${PREFIX}, and /usr/pkg/etc
for ${PKG_SYSCONFDIR}, without loss of generality.

# pkgsrc-specific notes

## Choice of jpeg implementation

ZoneMinder claims to benefit dramatically from using libjpeg-turbo.
Consider setting that as default in mk.conf
`JPEG_DEFAULT=libjpeg-turbo` and then *everything*.

## User and Group

zoneminder uses APACHE_USER and APACHE_GROUP.  These are www by
default, but people set them to fpm for use with nginx and php_fpm.
It is important that apache, zoneminder, and any existing directories
all agree.

# MySQL configuration and initial database creation

(It seems that zoneminder only works with MySQL.)

Condider adding `bind-address=127.0.0.1` to `etc/my.conf`, if you are
using mysql only for zoneminder and do not want it accessible from the
network.

See upstream instructions at
https://zoneminder.readthedocs.io/en/1.32.3/installationguide/ubuntu.html
which are for Ubuntu, but seem mostly generic.

Specifically, see "Step 5: Configure the ZoneMinder Database".

The default password is "zmpass".  You may (probably should) change
this to something else, and set ZM_DB_PASS in
e.g. /usr/pkg/etc/zm/zmpass.conf.

# Other setup

See "Step 6: Set permissions", and use APACHE_GROUP.

See "Step 9: Edit Timezone in PHP".  Otherwise, access to streams will
fail.  See https://github.com/ZoneMinder/ZoneMinder/issues/1552 for
more information.
 
# Web setup

## apache

See "Step 7: Configure Apache correctly", but edit the apache config
file instead of using the not-in-pkgsrc a2enmod command.

mod_cgid is a hard requirement.  zm appears to work without rewrite
and expire.  headers is default on.  Enabling a zoneminder apache
module does not make sense, but upstream maybe implies that you
should.

For now One needs to use prefork instead of event with cgid, because
php is built without threads.

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
avoid this in `zmpkg.pl`, it is likely necessary to kill the hanging
start script, and thus to write a script to do so, to enable reliable
starting.  This is likely an upstream issue, to be debugged after
pkgsrc is up to date.

# Upgrading from previous versions

As always, backup everything, diff all configs from upstream before
and minimize, save deltas, and merge to new upstreams keeping intended
changes.  This is going to be worse than most upgrades.

## Standard zoneminder advice

Upgrade a database from an older version of ZoneMinder via:

  zmupdate.pl -u root [-p <password>]

NB: Zoneminder 1.32 will attempt to remove config from the database
and place it in e.g. `/usr/pkg/etc/zm/conf.d/zmcustom.conf`.  The
package attempts to create the directory, but make one more backup
than you think you need.

## Zoneminder path woes

In theory, one wouldn't have to set paths, but it seems one does.  Go
over the list at
https://github.com/ZoneMinder/zoneminder/blob/release-1.32/INSTALL and
set some.

Probably, see (or create) conf.d/zmpaths.conf.

## Issues due to pkgsrc changes from 1.30 to 1.32

pkgsrc changed the config dir from /usr/pkg/etc to /usr/pkg/etc/zm, so
you should move zm.conf.

When editing in conf.d, beware zmcustom.conf~ which might or might not
also be read.

pkgsrc changed from /var/cache/zoneminder to /var/db/zoneminder.
While merging configs, pay extra attention to stray /var/cache
pathnames.

### Storage

Zoneminder has "Storage" configured (Options, Storage), and it is
possible that it used to be /var/cache/zoneminder/events and should
now be /var/db/zoneminder/events.

### Upload temp dir

One can configure uploads and a temp dir in which to create them.
That path is in the database as UPLOAD_LOC_DIR and can be a stray
source of /var/cache/zoneminder.

# Shared memory

Zoneminder tries to use a shm filesystem to store files that are then
mmap'd.  (1.28 used SysV shm but that is no longer relevant.)

On NetBSD, the compiled default might be /dev/shm but the right place
is /var/shm.  This can be changed in zmcustom.conf via ZM_PATH_MAP.

(One might need a lot of space, or to turn the buffer down to fewer
frames; this is not about pkgsrc.)

Somtimes, the shm file can get into a bad state and be zero length.
This might be a bad error path during camera timeouts; it seems to
happen more with bad wifi connections.  Turning up the timeouts in the
config (e.g. wait 10s or 30s before giving up instead of 2s) probably
also helps.  This is also not about pkgsrc.
