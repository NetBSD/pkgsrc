# $NetBSD: bsd.pkg.defaults.mk,v 1.128.2.1 2003/03/23 00:52:10 jmc Exp $
#

# A file providing defaults for pkgsrc and the packages collection.
# See the NetBSD mk.conf(5) and packages(7) manual page for a full
# description of all available options.
#

# ************************************************************************
# NOTE TO PEOPLE EDITING THIS FILE - USE LEADING SPACES, NOT LEADING TABS.
# ************************************************************************

#MANZ=
# gzip manual pages at installation time
# Possible: defined, not defined
# Default: not defined

#MKCRYPTO= no
# If not YES or yes, don't fetch, build or install crypto packages.
# Possible: not defined, no
# Default: yes

#OBJHOSTNAME=
# use hostname-specific object directories, e.g.  work.amnesiac, work.localhost
# OBJHOSTNAME takes precedence over OBJMACHINE (see below).
# Possible: defined, not defined
# Default: not defined

#OBJMACHINE=
# use machine-specific object directories, e.g.  work.i386, work.sparc
# Possible: defined, not defined
# Default: not defined

PKGSRC_LOCKTYPE?= none
# The type of locking which will be done if competing processes attempt to
# do work on one package directory simultaneously.
# + Locking requires that OBJHOSTNAME is set.
# + Locking may require the pkgsrc/pkgtools/shlock package to be installed
#   on certain OS types.
# + Sleep locking means that the process will sleep for ${PKGSRC_SLEEPSECS}
#   seconds, then try to acquire the lock, and sleeping again if it's not
#   available.
# + Once locking will try once to acquire the lock, and then fail.
# Possible: none, sleep, once
# Default: none

PKGSRC_SLEEPSECS?= 5
# The number of seconds to wait when PKGSRC_LOCKTYPE is sleep
# Possible: a positive integer
# Default: 5

#USETBL=
# Run raw manual pages through tbl(1) before piping through troff(1)
# when formatting manual pages.
# Possible: defined, not defined
# Default: not defined


#
# The following values are used to manage the packages collection as a whole.
#

#PKG_DEVELOPER=	yes
# Run a sanity check that package developers want:
#  * run check-shlibs to see that all binaries will find their libs
# Possible: defined, not defined
# Default: not defined

#PKG_REGISTER_SHELLS= YES
# Automatically register shells in /etc/shells
# Possible: YES, NO
# Default: YES

PKGSRC_RUN_TEST?=	no
# Run test target before install
# Possible: yes, no
# Default: no

#WRKOBJDIR=	/usr/tmp
# build here instead of in pkgsrc
# Possible: any path
# Default: not defined

LOCALBASE?=	/usr/pkg
# Where non-X-based packages will be installed
# Possible: any path
# Default: /usr/pkg

CROSSBASE?=	${LOCALBASE}/cross
# Where "cross" category packages install
# Possible: any path
# Default: ${LOCALBASE}/cross

#X11BASE?=	/usr/X11R6
# Where X11 is installed on the system.
# (and the default install path of X11 pkgs)
# Possible: any path
# Default: /usr/X11R6, or /usr/openwin for Solaris

#MOTIFBASE?=	/usr/X11R6
# Where Motif-2.0-compatible headers and libraries are installed
# on the system.
# Possible: any path
# Default: ${X11PREFIX} or where openmotif or lesstif is installed

#MOTIF12BASE?=	/usr/X11R6
# Where Motif-1.2-compatible headers and libraries are installed
# on the system.
# Possible: any path
# Default: ${X11PREFIX} or where lesstif12 is installed

DISTDIR?=	${_PKGSRCDIR}/distfiles
# Directory where original distribution
# files are stored.
# Possible: any path you like
# Default: /usr/pkgsrc/distfiles

#DIST_PATH=	/cdrom/0/distfiles:${HOME}/distfiles
# colon-delimited list of directories in which to search for
# ${DISTFILES} and ${PATCHFILES}.  If the requested file is not in any
# of the directories in ${DIST_PATH}, it will be downloaded into
# ${DISTDIR}.  If the requested file is in one of the directories in
# ${DIST_PATH}, a symbolic link will be made to it from ${DISTDIR}. 
# ${DIST_PATH} directories will will be searched before ${DISTDIR},
# letting a CD hold the main distfiles archive, and local ${DISTDIR}
# hold any updated distfiles, for example.
# Possible:  any directories
# Default: none

PACKAGES?=       ${_PKGSRCDIR}/packages
# Store generated packages on a per-architecture base
# Possible: any path you like
# Default: /usr/pkgsrc/packages

#PASSIVE_FETCH=
# Use ftp(1) in passive mode, for use behind filtering firewalls. 
# (Set by default in ftp(1) in NetBSD-current)
# Possible: defined, not defined
# Default: not defined

PATCH_FUZZ_FACTOR?= -F0
# Fuzz factor to use when applying patches.  Will only be applied when
# using a patch(1) that understands -F.  This should be a "?="
# setting, since package Makefiles may set this value, before
# /etc/mk.conf is read.
# Possible: "-Fn" where n is a number, none
# Default: "-F0"

#ACCEPTABLE_LICENSES=	fee-based-commercial-use no-commercial-use \
# 			no-profit limited-redistribution shareware
# Whitespace-delimited list of the types of license which are
# acceptable for installation.  (apart from standard "free" licenses
# such as Berkeley/CMU and GPL).  Possible values are presented below.
#
# Default: none

#ACCEPTABLE_LICENSES+=	IDEA-licence
# Enable it if you accept the license terms for libidea
# and would like to build libidea.  see pkgsrc/security/libidea.
#ACCEPTABLE_LICENSES+=	adobe-acrobat-license
# Enable it if you accept the usage policy for Adobe Acrobat
# and would like to build it.  see pkgsrc/print/acroread.
#ACCEPTABLE_LICENSES+=	amiwm-license
# Enable it if you accept the license terms for amiwm
# and would like to build amiwm.  see pkgsrc/wm/amiwm.
#ACCEPTABLE_LICENSES+=	astrolog-license
# Enable it if you accept the license terms for astrolog
# and would like to build astrolog.  see pkgsrc/misc/astrolog.
#ACCEPTABLE_LICENSES+=	citrix_ica-license
# Enable it if you accept the license proposed at
# http://www.citrix.com/download/unix-downloads.htm
# when you try to download the corresponding client to download and build
# the package.
#ACCEPTABLE_LICENSES+=	csound-license
# Enable it if you accept the redistribution/use license for csound and would
# like to build csound.  see pkgsrc/licenses/csound-license
#ACCEPTABLE_LICENSES+=	cyrus-imapd-license
# Enable it if you accept the license terms for cyrus-imapd
# and would like to build cyrus-imapd.  see pkgsrc/mail/cyrus-imapd.
#ACCEPTABLE_LICENSES+=	emiclock-license
# Enable it if you accept the license terms for emiclock
# and would like to build it.  see pkgsrc/time/emiclock.
#ACCEPTABLE_LICENSES+=	fee-based-commercial-use
# Enable it if you are okay to build/use third-party software, which require
# fees for commercial use (i.e. you are willing to pay, or you are
# non-commercial).
#ACCEPTABLE_LICENSES+=	graphviz-license
# Enable it if you accept the license terms for graphviz
# and would like to build it. see pkgsrc/graphics/graphviz.
#ACCEPTABLE_LICENSES+=	jdk-license
# Enable it if you accept the license terms for jdk
# and would like to build jdk.  see pkgsrc/lang/jdk.
#ACCEPTABLE_LICENSES+=	jdk13-license
# Enable it if you accept the download license for Sun JDK1.3 and would
# like to build Sun JDK13.  see pkgsrc/langun-jre13.
#ACCEPTABLE_LICENSES+=	kermit-license
# Enable it if you accept the redistribution license for ckermit and would
# like to build ckermit.  see pkgsrc/licenses/kermit-license
#ACCEPTABLE_LICENSES+=	limited-redistribution
# Enable it if you are okay to build/use third-party software, which has
# restriction on redistribution (i.e. you will obey the restriction on
# redistribution it imposes).
#ACCEPTABLE_LICENSES+=	majordomo-license
# Enable it if you accept the license terms for majordomo
# and would like to build majordomo.  see pkgsrc/mail/majordomo.
#ACCEPTABLE_LICENSES+=	maude-license
# Enable it if you filled out and returned the license found at
# http://maude.csl.sri.com/license/license.html
# and want to build maude.
#ACCEPTABLE_LICENSES+=	mosaic-license
# Enable it if you accept the license terms for mosaic
# and would like to build mosaic.  see pkgsrc/www/Mosaic.
#ACCEPTABLE_LICENSES+=	ms-ttf-license
# Enable it if you accept the license terms for Microsoft TrueType fonts
# and would like to install them. see pkgsrc/fonts/ms-ttf.
#ACCEPTABLE_LICENSES+=	mush-license
# Enable it if you accept the license terms for mush
# and would like to build mush.  see pkgsrc/mail/mush.
#ACCEPTABLE_LICENSES+=	nntpclnt-license
# Enable it if you accept the license terms for nntpclnt
# and would like to build nntpclnt.  see pkgsrc/news/nntpclnt.
#ACCEPTABLE_LICENSES+=	no-commercial-use
# Enable it if you are okay to build/use third-party software, which is not
# for commercial use (i.e. you are non-commerical)
#ACCEPTABLE_LICENSES+=	no-profit
# Enable it if you are okay to build/use third-party software, which is not
# for for-profit use (i.e. you will use the software for non-profit purpose)
#ACCEPTABLE_LICENSES+=	opera-license
# Enable it if you accept the redistribution license for opera and would
# like to build opera.  see pkgsrc/licenses/opera-license
#ACCEPTABLE_LICENSES+=	palmos-sdk-license
# Enable if you agree with the license for using the PalmOS SDK.
# Used by pkgsrc/devel/palmos-includes. For the license, see
# pkgsrc/licenses/palmos-sdk-license.
#ACCEPTABLE_LICENSES+=	pine-license
# Enable it if you accept the license terms for pine
# and would like to build pine.  see pkgsrc/mail/pine.
#ACCEPTABLE_LICENSES+=	portsentry-license
# Enable it if you accept the license terms for portsentry
# and would like to build portsentry.  see pkgsrc/security/portsentry.
#ACCEPTABLE_LICENSES+=	shareware
# Enable it if you are okay to build/use shareware.
#ACCEPTABLE_LICENSES+=	srp_client-license
# Enable it if you accept the license terms for srp_client
# and would like to build srp_client.  see pkgsrc/security/srp_client.
#ACCEPTABLE_LICENSES+=	sun-jsdk20-license
# Enable it if you accept the download license for Sun JSDK and would
# like to build Sun JSDK.  see pkgsrc/lang/jdk.
#ACCEPTABLE_LICENSES+=	sun-swing-license
# Enable it if you accept the download license for Sun's Swing (JFC) toolkit
# and would like to build JFC.  see pkgsrc/x11/swing.
#ACCEPTABLE_LICENSES+=	trn-license
# Enable it if you accept the license terms for trn
# and would like to build trn.  see pkgsrc/news/trn.
#ACCEPTABLE_LICENSES+=	trplayer-license
# Enable it if you accept the license terms for trplayer
# and would like to build trplayer.  See pkgsrc/audio/trplayer.
#ACCEPTABLE_LICENSES+=	unarj-license
# Enable it if you accept the license terms for the unarj archiver
# and would like to build unarj.  see pkgsrc/archivers/unarj.
#ACCEPTABLE_LICENSES+=	unrar-license
# Enable it if you accept the license terms for the unrar archiver
# and would like to build unrar.  see pkgsrc/archivers/unrar.
#ACCEPTABLE_LICENSES+=	zoo-license
# Enable it if you accept the license terms for the zoo archiver
# and would like to build zoo.  see pkgsrc/archivers/zoo.

#SPECIFIC_PKGS=
# Don't use the default of all packages (from the top-level of the
# pkgsrc tree), and use the values of the definitions
# SITE_SPECIFIC_PKGS, HOST_SPECIFIC_PKGS, GROUP_SPECIFIC_PKGS, and
# USER_SPECIFIC_PKGS.
# Possible: defined, not defined
# Default: not defined

#SITE_SPECIFIC_PKGS=
# List of packages that are wanted for each host on the site.  Each
# package in the list is of the form <category>/<package>.
# Possible: any combination of packages
# Default: not set

#HOST_SPECIFIC_PKGS=
# List of packages that are wanted for this particular host/machine. 
# Each package in the list is of the form <category>/<package>.
# Possible: any combination of packages
# Default: not set

#GROUP_SPECIFIC_PKGS=
# List of packages that are wanted for this group of users.  Each
# package in the list is of the form <category>/<package>.
# Possible: any combination of packages
# Default: not set

#USER_SPECIFIC_PKGS=
# List of packages that are wanted for this particular user.  Each
# package in the list is of the form <category>/<package>.
# Possible: any combination of packages
# Default: not set

#EXTRACT_USING_PAX=
# Use pax(1) to extract archives, rather than GNU tar.
# Possible: defined, not defined
# Default: not defined

#FAILOVER_FETCH=
# Perform a checksum at "make fetch" time.  If the checksum doesn't
# match the stored value, try to retrieve the file from the next site
# in the list
# Possible:  defined, not defined
# Default: not defined

#MASTER_SORT=        .ac.at .at .de .ch .se .fi .no
# Whitespace delimited list of preferred download locations. 
# MASTER_SITES and PATCH_SITES will be reordered according to the hosts'
# address last components.
# Possible: list of domain name suffixes
# Default: none

#MASTER_SORT_REGEX=  ftp://.*/ 
# Same as MASTER_SORT, but takes a regular expression for more
# flexibility in matching.  Regexps defined here have higher priority
# than MASTER_SORT.  This example would prefer ftp transfers over
# anything else.
# Possible: Regexps as in awk(1)
# Default: none

#PATCH_DEBUG=
# Used to debug patches as they are applied
# Possible: defined, not defined
# Default: not defined

#PKG_FC=
# The Fortran compiler used to compile Fortran code contained in
# packages.
# Possible: any Fortran compiler
# Default: none

.if ${OPSYS} == "SunOS"
#IMAKE?=	${X11BASE}/bin/imake -DHasGcc2=YES -DHasGcc2ForCplusplus=YES
# Sun ONE Studio (formerly known as WorkShop and Forte) compliers can be used
# with:
#IMAKE?=	${X11BASE}/bin/imake
# Possible: any path and valid flags
# Default: ${X11BASE}/bin/imake -DHasGcc2=YES -DHasGcc2ForCplusplus=YES
.endif

PRE_ROOT_CMD?=	${TRUE}
# Command to be run by normal user, just before becoming root (see
# SU_CMD) to install the package.  For example, "chmod -R o+w ${WRKDIR}"
# would allow others to write and modify files below ${WRKDIR}.
# Possible: any shell commands
# Default: none

SU_CMD?= ${ROOT_CMD}
# Command to perform before "make install", if the user does not have
# an effective uid of 0.  A possible substitute is "sudo sh -c"
# Possible: su, sudo, or priv, with appropriate arguments
# Default: dependent on operating system. For NetBSD: ${SU} - root -c

SU_CMD_PATH_APPEND?=/sbin:/usr/sbin
# Additional directories (in a colon separated list) to be added to the 
# PATH environment variable when running ${SU_CMD}.
# Default: /sbin:/usr/sbin

FATAL_OBJECT_FMT_SKEW?=yes
# If there is a pre-requisite package, which has a different object format
# from that currently being used, halt execution. One (rare) situation where
# it is possible for the difference to be harmless is where the pre-requisite
# package provides an executable, not a library.
# Possible: yes, no
# Default: yes

WARN_NO_OBJECT_FMT?=yes
# Packages installed on a machine before OBJECT_FMT was added to the
# BUILD_DEFS definitions (on 29th September 1999) cannot say which 
# object format they are in.  This will cause a warning to be displayed. 
# Set this to "no" to stop the warning message being shown.
# Possible: yes, no
# Default: yes 

#SMART_MESSAGES=yes
# Display the make(1) target, and the current stack of packages being built,
# when displaying messages during package builds.
# Possible: defined, not defined
# Default: not defined

#BINPKG_SITES=...
# Whitespace seperated list of URLs for binary packages. Directories
# "All" etc. are expected in the named place, variables "rel" and
# "arch" are replaced with OS release ("1.5", ...) and architecture
# ("mipsel", ...)
# Possible: any ftp url, see above.
# Default: ftp://ftp.netbsd.org/pub/NetBSD/packages/$${rel}/$${arch}

#BIN_INSTALL_FLAGS=
# List of flags passed to pkg_add(8) in the bin_install package.
# Possible: -v, -u, etc. See pkg_add(8)
# Default: (no option)

#LOCALPATCHES=...
# Directory where local patches are stored. See pkgsrc/Packages.txt.
# Possible: Any local directory
# Default: none

#
#	Definitions used only in the packages collection
#

#AMANDA_SMB=
# Used in amanda-client and amanda-dev-client to enable backup with
# smbclient.
# Possible: defined, not defined
# Default: not defined

AMANDA_USER?=	backup
# Used in the amanda packages to specify the login user and group
# responsible for backups.
# Possible: any user name
# Default: backup

AMANDA_VAR?=	/var/amanda
# Specifies the directory in which amanda puts its logs and status
# files. 
# Default: /var/amanda

#APACHE_CUSTOM_CFLAGS=
# Used in apache and apache6 to pass extra CFLAGS to the compiler during
# the build.
# Possible: any legal compiler flags, e.g. -O6 -DHARD_SERVER_LIMIT=512
# Default: not defined

#APACHE_PERF_TUNING=	YES
# Used in apache and apache6 to optimize for maximum performance.
# Possible: not defined, YES
# Default: not defined

APACHE_USER?=	www
# Used in apache, apache2, apache6, isap, and smb2www to specify the user
# allowed to execute the `suexec' wrapper.  Expected to be the user the
# httpd server normally runs as.
# Possible: any user name
# Default: www

APACHE_GROUP?=	www
# Used in apache, apache2, apache6, squirrelmail, and iasp to specify
# the default group of the user allowed to execute the `suexec' wrapper.
# Expected to be the group the httpd server normally runs as.
# Possible: any group name
# Default: www

#APACHE_SUEXEC=	YES
# Used in apache, apache2, and apache6 to enable Switch User For Exec
# support.  See http://www.apache.org/docs/suexec.html for more informations.
# Possible: not defined, YES
# Default: not defined

#APACHE_SUEXEC_CONFIGURE_ARGS=	--suexec-uidmin=1000
# Used in apache, apache2, and apache6 to specify additional suexec options
# to be passed to the configure script.
# Possible: any --suexec-* options recognized by the Apache configure script.
# Default: not defined

APACHE_SUEXEC_DOCROOT?=	${LOCALBASE}/share/httpd/htdocs                
# Used in apache, apache2, and apache6 to specify the document space in
# which suexec will be allowed to work.      
# Possible: Any valid directory                                              
# Default: ${LOCALBASE}/share/httpd/htdocs                                   

ARLA_CACHE?=	${LOCALBASE}/cache
# Used in arla to specify the location of the cache used by arla. Should
# be on a local disk.
# Default: ${LOCALBASE}/cache

ATERM_USE_KANJI?= NO
# Used in aterm to enable kanji support.
# Possible: YES or undefined or anything else
# Default: NO

ATERM_USE_BIG5?= NO
# Used in aterm to enable chinese support. (?)
# Possible: YES or undefined or anything else
# Default: NO

ATERM_USE_XTERM_SCROLL?= NO
# Used in aterm to use a xterm-like scrollbar instead of a NeXT-like.
# Possible: YES or undefined or anything else
# Default: NO

ATERM_USE_GREEK?= NO
# Used in aterm to enable greek keyboard support.
# Possible: YES or undefined or anything else
# Default: NO

#AVIFILE_USE_QT=	YES
# Used in avifile-devel to enable support for qt2. These utilities will be
# built in addition to non-qt version: avi{bench,cat,make,recompress,type}.
# aviplay (qt-based player that uses avifile libraries) will be built too,
# but it has problems with threads and does not work yet.
# Default: not defined

#BASH_STATIC=	YES
# Used in bash2 to link it statically (for use as a root shell).
# Possible: not defined, YES
# Default: not defined

#BATTLEBALL_USE_MESA=
# Used in battleball to build in support for OpenGL/Mesa. Will use
# Mesa-glx (rather than Mesa) if Mesa-glx is already installed.
# Possible: not defined, YES
# Default: not defined

#BULK_PREREQ=
# Used during bulk package builds.  Packages listed in this variable are
# assumed to be required to build all packages.  Only a very limited number
# of packages belong in this variable.  An example of an appropriate package
# is pkgtools/xpkgwedge.  Currently pkgtools/digest is always added to this
# list.
# Possible: category/pkg
# Default: not defined

#CDRECORD_CONF= ${PKG_SYSCONFDIR}/cdrecord.conf
# The location of the cdrtools/cdrecord configuration file. The
# sysutils/cdrecord pkg issues a warning if the cdrtools default of
# /etc/default/cdrecord is changed, and the man pages are updated
# accordingly. This is required by the cdrtools license.
# Possible: any file name
# Default: ${PKG_SYSCONFDIR}/cdrecord.conf

CUPS_GROUP?=	sys
# Used in cups to specify the group to run CUPS commands as.
# Possible: any group name
# Default: sys

CUPS_USER?=	lp
# Used in cups to specify the user to run CUPS commands as and to create
# temporary files in the /var/spool/cups/tmp directory.
# Possible: any user name
# Default: lp

CYRUS_GROUP?=	mail
# Used in cyrus-imapd, cyrus-imapd21, cyrus-sasl, and cyrus-sasl2 to
# specify the group used for installing setuid programs.
# Possible: any group name
# Default: mail

CYRUS_USER?=	cyrus
# Used in cyrus-imapd, cyrus-imapd21, cyrus-sasl, and cyrus-sasl2 to
# specify the userid used for installing setuid programs.
# Possible: any user name
# Default: cyrus

DEFANG_GROUP?=	defang
# Used in the mimedefang package to specify the group to run commands as
# Possible: any group name
# Default: defang

DEFANG_USER?=	defang
# Used in the mimedefang package to specify the user to run commands as
# Possible: any user name
# Default: defang

DEFANG_SPOOLDIR?=	/var/spool/MIMEDefang
# Location of spool and quarantined files for the mimedefang package
# Default: /var/amanda

#DEFAULT_IRC_SERVER=
# Used in ircII to set the default irc server. 
# Possible: see the list at
# http://www.irchelp.org/irchelp/networks/servers/efnet.html
# Default: not defined

#DEFAULT_SERIAL_DEVICE=
# Used to provide a default setting for the serial device for
# various packages which communicate over the serial port.
# Possible:  /dev/your_favorite_serial_device
# Default: defaults for various machine_archs are set in mk/defs.${OPSYS}.mk

DELIVER_SUID?=	NO
# Used to decide if deliver should be installed suid root.
# Possible: YES, NO
# Default: NO

DT_LAYOUT?= US
# Used by dt package to specify the keyboard layout.
# Possible: US, FI, FR, GER, DV
# Default: FI

ELK_GUI?=	none
# Used by elk to determine which GUI API modules are enabled.
# Possible: none, or some combination of xaw and/or motif
# Default: none

EMACS_USE_POP?= yes
# Used by emacs package to determine whether pop support is enabled or not.
# Possible: yes, no
# Default: yes

#EMACS_USE_X=
# Used by emacs package to determine whether X support is enabled or not.
# If defined, the value is directly passed as argument of --with-x.
# If not defined, the configure script will configure automatically.
# Possible: yes, no, not defined
# Default: not defined

#EMACS_USE_X_TOOLKIT=
# Used by emacs package to determine what kind of toolkit support is enabled.
# If defined, the value is directly passed as argument of --with-x-toolkit.
# If not defined or defined to yes, the configure script will pick up an
# appropriate one.  E.g, if X11R5 or later is found, lucid will be used.
# Possible: yes, no, not defined, athena, lucid, motif
# Default: not defined

FETCHMAIL_USE_SSL?=	YES
# Enable SSL in fetchmail (for pop and imap connections)
# Possible: YES, NO
# Default: YES

FOX_USE_XUNICODE?=	YES
# Used in fox to build in support for Unicode by XUnicode. See
# http://www.ab.wakwak.com/~tino/jatk/fox/ (in japanese) for more information.
# Possible: YES, NO
# Default: YES

FREEWNN_USER?=	wnn
# Used in the ja-freewnn-server-bin package to specify the Free wnn user.
# Possible: any user name
# Default: wnn

FREEWNN_GROUP?=	jserver
# Used in the ja-freewnn-server-bin package to specify the Free wnn group.
# Possible: any group name
# Default: jserver

GAWK_ENABLE_PORTALS?=	NO
# Used by gawk package to enable/disable handling file names that start with
# `/p/' as a 4.4 BSD type portal file, i.e., a two-way pipe for `|&'.
# Possible: YES, NO
# Default: NO

GIMP_WITH_HELPBROWSER?=	no
# Set to "yes" to compile gimp against GNOME libs and get a working
# help browser. Adds quite some bloat in the form of dependencies.
# Possible: yes, no
# Default: no

GNU_PROGRAM_PREFIX?=	g
# This is the prefix to add for GNU programs, like gls or gnutouch.
# Possible: g, gnu, empty, ...
# Default: g

#GQMPEG_NO_JAPANESE?=	yes
# Can be enabled to handle keep gqmpeg from interpreting ID3 tags
# different, to make it possible to read japanese language tags, which
# may be a problem with tags in other encodings (e.g. windows-1251 as
# commonly used for russian-language tags).
# Possible: yes, no, not defined
# Default: not defined (-> Japanese support enabled)

#GQMPEG_NO_RUSSIAN?=	yes
# Can be enabled to disable russian ID3 tag support
# Possible: yes, no, not defined
# Default: not defined (-> Russian support enabled)

#GRUB_NETWORK_CARDS=
# Compile netboot support for the listed network interface cards into GRUB.
# Use e.g. "rtl8139" for RealTek 8139 support or "eepro100 epic100" for
# Intel Etherexpress Pro/100 and SMC EtherPower II support.
# Default: not defined (-> no netboot support)

#GRUB_SCAN_ARGS=
# Can be used to supply additional configure arguments for netboot support in
# GRUB. Set e.g. "GRUB_NETWORK_CARDS" to "ne" and "GRUB_SCAN_ARGS" to
# "--enable-ne-scan=0x300" to let the boot loader search for an NE 2000 ISA
# card at I/O offset 0x300.
# Default: not defined

IMAP_UW_CCLIENT_MBOX_FMT?=	unix
# Used in imap-uw to set the default format used by c-client programs for
# new mailbox creation.  Check the UW IMAP documentation for more details
# regarding the pros and cons of the various mailbox formats.
#
# Possible: mbox, mbx, mh, mmdf, mtx, mx, news, phile, tenex, unix
# Default: unix

#IMAP_UW_NO_CLEARTEXT?=	YES
# Used in imap-uw to disallow plaintext passwords except when SSL or TLS
# is used. This effectively disallows cleartext passwords.
#
# Possible: not defined, YES
# Default: not defined

#IMAP_UW_NO_SSL?= YES
# Used in imap-uw to build without any SSL or TLS support at all. Note that
# it doesn't make any sense to enable this together with IMAP_UW_NO_CLEARTEXT,
# nor is is it fully supported in pkgsrc for all clients.
#
# Possible: not defined, YES
# Default: not defined

IMDICTDIR?=	/var/dict
# Specify the directory for input method's dictionary installation.
# Possible: any valid location
# Default: /var/dict 

INN_DATA_DIR?= /var/news
# Used by inn to specify the data directory.
# Possible: any path you like
# Default: /var/news

IRCD_HYBRID_SMALL_NET?=		YES
# Used by ircd-hybrid to tune various ircd paramaters when running
# small IRC networks so the daemon does not use much resources.
# A set of variables - see below - can then be defined to fine tune the daemon
# behaviour.
# Possible: YES, NO
# Default: YES

#IRCD_HYBRID_LINK_PREALLOCATE=
# Used by ircd-hybrid when IRCD_HYBRID_SMALL_NET is "YES". Specify
# the number of server linkd to preallocate.
# Possible: nearly any integer value
# Default: 1024 from source, 64 if IRCD_HYBRID_SMALL_NET is "YES"

#IRCD_HYBRID_CLIENTS_PREALLOCATE=
# Used by ircd-hybrid when IRCD_HYBRID_SMALL_NET is "YES". Specify
# the number of client structures to preallocate.
# Possible: nearly any integer value
# Default: 1024 from source, 64 if IRCD_HYBRID_SMALL_NET is "YES"

#IRCD_HYBRID_USERS_PREALLOCATE=
# Used by ircd-hybrid when IRCD_HYBRID_SMALL_NET is "YES". Specify
# the number of user structures to preallocate.
# Possible: nearly any integer value
# Default: 1024 from source, 64 if IRCD_HYBRID_SMALL_NET is "YES"

#IRCD_HYBRID_NICKNAMEHISTORYLENGTH=
# Used by ircd-hybrid when IRCD_HYBRID_SMALL_NET is "YES". Specify
# the number of entries in the nickname history.
# Possible: nearly any integer value
# Default: 15000 from source, 1000 if IRCD_HYBRID_SMALL_NET is "YES"

#IRCD_HYBRID_MAXSENDQLENGTH=
# Used by ircd-hybrid when IRCD_HYBRID_SMALL_NET is "YES". Specify
# the maximum -in bytes- of internal send buffering for sockets.
# Possible: nearly any integer value
# Default: 9000000 from source, 500000 if IRCD_HYBRID_SMALL_NET is "YES"

#IRCD_HYBRID_INITIAL_DBUFS=
# Used by ircd-hybrid when IRCD_HYBRID_SMALL_NET is "YES". Specify
# the initial number of dbufs (dynamic buffering of a byte stream,
# similar to mbufs) to preallocate.
# Possible: nearly any integer value
# Default: 4000 from source, 300 if IRCD_HYBRID_SMALL_NET is "YES"

#IRCD_HYBRID_HARD_FDLIMIT_=
# Used by ircd-hybrid when IRCD_HYBRID_SMALL_NET is "YES". Specify
# the maximum number of file descriptor the daemon will use.
# Possible: 1 <> maximum file descriptor the system would give you
# Default: 256 from source, 90 if IRCD_HYBRID_SMALL_NET is "YES"

#IRCD_HYBRID_INIT_MAXCLIENTS=
# Used by ircd-hybrid when IRCD_HYBRID_SMALL_NET is "YES". Specify
# the maximum number of clients allowed to connect to the daemon.
# Possible: 1<> ~IRCD_HYBRID_HARD_FDLIMIT_
# Default: 200 from source, 40 if IRCD_HYBRID_SMALL_NET is "YES"

IRCD_HYBRID_USE_LOGFILE?=       YES
# Used by ircd-hybrid. Specify if the daemon should use a logfile.
# Note: can be used even when IRCD_HYBRID_USE_SYSLOG is "YES".
# Possible: YES, NO
# Default: YES
 
IRCD_HYBRID_USE_SYSLOG?=        NO
# Used by ircd-hybrid. Specify if the daemon should use syslog.
# Note: can be used even when IRCD_HYBRID_USE_LOGFILE is "YES".
# Possible: YES, NO
# Default: NO

IRCD_HYBRID_DPATH?=	/etc/ircd-hybrid/
# Used by ircd-hybrid. Specify the directory pathname where the daemon expects
# various configuration files.
# Possible: any path, with a trailing `/'
# Default: /etc/ircd-hybrid/

IRCD_HYBRID_LPATH?=	/var/log/ircd-hybrid.log
# Used by ircd-hybrid. Specify the pathname of the daemon logfile.
# Note: only used if IRCD_HYBRID_USE_LOGFILE is "YES".
# Possible: any path
# Default: /var/log/ircd-hybrid.log

IRCD_HYBRID_FNAME_USERLOG?=	/var/log/ircd-hybrid.users.log
# Used by ircd-hybrid. Specify the pathname of the user connections logfile.
# IRCD_HYBRID_USE_SYSLOG should be set to "YES" for this logfile be used.
# Possible: any path
# Default: /var/log/ircd-hybrid.users.log

IRCD_HYBRID_FNAME_OPERLOG?=	/var/log/ircd-hybrid.opers.log
# Used by ircd-hybrid. Specify the pathname of the operator connections
# logfile.
# Possible: any path
# Default: /var/log/ircd-hybrid.opers.log

IRCD_HYBRID_PPATH?=		/var/run/ircd-hybrid.pid
# Used by ircd-hybrid. Specify the pathname of the daemon pid file.
# Possible: any path
# Default: /var/run/ircd-hybrid.pid

IRCD_HYBRID_SYSLOG_FACILITY?=	LOG_LOCAL4
# Used by ircd-hybrid. Specify which syslog facility the daemon should use
# when IRCD_HYBRID_USE_SYSLOG is "YES".
# Possible: any syslog facility (LOG_*)
# Default: LOG_LOCAL4

IRCD_HYBRID_INIT_LOG_LEVEL?=	L_NOTICE
# Used by ircd-hybrid. Specify initial minimum level from which the daemon logs
# events. This is unrelated from syslog() level.
# Possible: L_CRIT, L_ERROR, L_WARN, L_NOTICE, L_TRACE, L_INFO, L_DEBUG
# Default: L_NOTICE

IRCD_HYBRID_IRC_USER?=		irc
# Used by ircd-hybrid. Specify the user name under which the daemon runs.
# Possible: any user name
# Default: irc

IRCD_HYBRID_IRC_GROUP?=		irc
# Used by ircd-hybrid. Specify the group name under which the daemon runs.
# Possible: any group name
# Default: irc

IRCD_HYBRID_NETWORK_NAME?=	PKGSRCNet
# Used by ircd-hybrid. Specify the IRC network name advertised by the daemon.
# Possible: anything
# Default: PKGSRCNet

IRCD_HYBRID_NETWORK_DESC?=	Package Source Network
# Used by ircd-hybrid. Specify the IRC network description advertised by the 
# daemon.
# Possible: anything
# Default: Package Source Network

#IRRD_USE_PGP=
# Used by irrd package to specify the version of PGP to use, if any.
# Possible: 5, 2, not defined
# Default: not defined
# [XXX: configure will locate pgpv or pgp]

#IRSSI_USE_PERL=	YES
# Build irssi with perl so you can load scripts written in perl.
# Possible: YES, not defined
# Default: not defined

#JB_FQHOSTNAME=
# Used by jitterbug package to include the fully-qualified domain name
# of the host.
# Possible: defined, not defined
# default: not defined

JB_GROUP?=jitter
# Used by jitterbug package for groupname
# Possible: any valid groupname
# Default: jitter

JB_GROUPID?=509
# Used by jitterbug package for gid of JB_USER.
# Possible: any valid gid
# Default: 509

#JB_LOCALMAIL=
# Used by jitterbug package as the mail alias to receive mail from
# jitterbug
# Possible: any valid mail alias
# Default: none

JB_PACKAGE?= test
# Used by jitterbug to determine the type of package to be installed.
# Possible: test, production
# Default: test

JB_USER?=jitter
# Used by jitterbug package for username
# Possible: any valid username
# Default: jitter

JB_USERID?=509
# Used by jitterbug package for uid of JB_USER.
# Possible: any valid uid
# Default: 509

JAKARTA_HOME?= ${JAVA_HOME}/jakarta
# Used by the www/jakarta-tomcat package to choose an install location
# Possible: any directory
# Default: ${JAVA_HOME}/jakarta

#JAVA_HOME=
# Location of jvm to be used by pkgsrc.  Java-based packages will be installed
# in ${LOCALBASE}/lib/java, so that they are available to all jvms.
# 
# Possible: any directory
# Default: home of JVM chosen by ${PKG_JVM}

JDK_HOME?= ${LOCALBASE}/java
# Used by the lang/JDK package to choose an install location
# Possible: any directory, e.g. /usr/jdk
# Default: ${LOCALBASE}/java

JSDK_HOME?= ${JAVA_HOME}/jsdk
# Location for Java Servlet Development Kit installed by www/jsdk20
# Possible: any directory
# Default: ${JAVA_HOME}/jsdk

#KERBEROS=
# Used in many packages to specify use of a Kerberos (or compatible)
# subsystem.  Requires Kerberos libraries in /usr/lib.
# Possible: defined, not defined
# Default: not defined

#KERMIT_SUID_UUCP
# If set to YES or yes, install kermit binary set-uid uucp. Permits an 
# unprivileged user to access the serial ports, with default permissions
# on the /dev/tty0* special files.
# Possible: YES, yes, not defined
# Default: not defined

#KJS_USE_PCRE=
# Used in kdelibs2 to determine if kjs (javascript) should use Perl
# Compatible Regular Expressions (pcre)
# Possible: yes, not defined
# Default: not defined

#KNEWS_DOMAIN_FILE=
# Used in the knews package to set the domain name from the contents
# of this file.
# Possible: any valid path
# Default: none

#KNEWS_DOMAIN_NAME=
# Used in the knews package to set the domain name.
# Possible:  almost anything really, usually a FQDN.
# Default: none

#KTERM_USE_WALLPAPER=
# Used in kterm package to support wallpaper
# Possible: not defined, YES
# Default: not defined

#LAME_USE_GTK=
# Used in lame package to compile in the graphical analyzer (which uses
# GTK).
# Possible: not defined, defined
# Default: not defined

#LIBDVDCSS_HOMEPAGE=
# Used in libdvdcss package as the homepage - we are unable to point this
# to one of the real sites for legal reasons
# Possible: any libdvdcss site
# Default: not defined

#LIBDVDCSS_MASTER_SITES=
# Used in libdvdcss package as the master site - we are unable to point this
# to one of the real sites for legal reasons
# Possible: any libdvdcss site
# Default: not defined

#LIBWRAP_FWD=
# Used in ssh package to make libwrap also compare against forwarded
# connection attempts
# Possible: not defined, YES
# Default: not defined

#LATEX2HTML_ICONPATH=
# Used in the latex2html package to set URL prefix for where to
# find latex2html's icons.
# Possible:  a URL prefix
# Default: none

LINUX_LOCALES?=								\
	 af ar bg br ca cs cy da de el en eo es et eu fi fo fr ga gl \
	    he hr hu hy id is it ja ka kl ko lo lt lv nl no oc pl pt ro \
	    ru sk sl sr sv th tr uk vi wa zh
# Used in linux-locale package to install specify language(s)
# Possible: af ar bg br ca cs cy da de el en eo es et eu fi fo fr ga gl \
#	    he hr hu hy id is it ja ka kl ko lo lt lv nl no oc pl pt ro \
#	    ru sk sl sr sv th tr uk vi wa zh
# Default: all languages

LPRNG_PRIV_PORTS?=	NO
# Used by LPRng to require connections to be from privileged ports.
# Possible: YES, or NO.
# Default: NO

LPRNG_SUID?=		YES
# Used by LPRng to enable setuid installation of LPRng binaries.
# Possible: YES, or NO.
# Default: YES 

LSOF_MORE_SECURE?=	0
# Used in lsof to specify that non-root users can only view their own files
# Possible:	0 (allow non-root users to view all open files), or
#		1 (only allow root to view all open files)
# Default: 0

LSOF_LESS_SECURE_SOCKETS?=	0
# Used in lsof to specify that non-root users should still be able to view
# all open sockets even if LSOF_MORE_SECURE is set.  If LSOF_MORE_SECURE is
# not set (ie, is zero), this option has no effect.
# Possible:	0 (don't allow non-root users to see sockets they don't own)
#		1 (allow all sockets to be viewed at all times)
# Default: 0

LYNX_SCREEN_LIB?=	curses
# Used in lynx and lynx-current to set which screen library to use.
# Possible: slang, ncurses, curses.
# Default: curses

#M68060=
# Used mostly by packages (e.g.:  pgp2, ssh) with have fast
# 68020/030/040 assembler routines for multiprecision arithmetic,
# which use the 32/64bit mul/div instruction.  These instructions are
# software emulated on the 68060, thus very slow.  Set to YES when
# compiling for the 68060 cpu.
# Possible: not defined, YES.
# Default: not defined.

MAJORDOMO_GROUP?= majordom
# Used by the majordomo package as the groupid majordomo runs at.
# Possible: any
# Default: majordom

MAJORDOMO_TMPDIR?= /var/tmp
# Used by the majordomo package as the directory to store temp files.
# Possible: any directory.
# Default: /var/tmp

MAJORDOMO_USER?= majordom
# Used by majordomo package as the userid majordomo runs at.
# Possible: any
# Default: majordom

MOZILLA_USE_XFT?=	NO
# Used by mozilla packages to enable Xft support where available.
# Possible: YES, NO
# Default: NO

MPLAYER_ENABLE_RUNTIME_CPU_DETECTION?= YES
# Used by mplayer to enable runtime CPU detection -- this makes
# binary packages work on different machines than the one compiled one,
# but may be slower.
# Note that this only takes effect on i386 and that binary packages made with
# this option set to NO will only run reliably on a machine of the same
# CPU type.
# Possible: YES, NO
# Default: NO

MPLAYER_USE_REALMEDIA?= NO
# Used by mplayer to enable realmedia support by using the realplayer
# libraries. Note that this only works on i386 and also adds a
# dependency for the linux emulation to this package.
# Possible: YES, NO
# Default: NO

#MOTIF_TYPE?=	openmotif
# Used by motif.buildlink2.mk to choose which Motif-2.0-compatible
# installation to use.  This value is also automatically set by
# motif.buildlink2.mk to whichever Motif-2.0 installation represented by
# the possible values below is already installed, but defaults to
# ${MOTIF_TYPE_DEFAULT}.  This value is ignored if MOTIFBASE is
# explicitly set.
# Possible: openmotif, lesstif, dt (Irix and Solaris only)
# Default: ${MOTIF_TYPE_DEFAULT}

#MOTIF_TYPE_DEFAULT?=	openmotif
# Used by motif.buildlink2.mk as the final default value for MOTIF_TYPE.
# Possible:  openmotif, lesstif, dt (Irix and Solaris only)
# Default: openmotif, or dt (Irix and Solaris only)

#MOTIF12_TYPE?=	lesstif12
# Used by motif.buildlink2.mk to choose which Motif-1.2-compatible
# installation to use.  This value is also automatically set by
# motif.buildlink2.mk to whichever Motif-1.2 installation represented by
# the possible values below is already installed, but defaults to
# ${MOTIF12_TYPE_DEFAULT}.  This value is ignored if MOTIF12BASE is
# explicitly set.
# Possible: lesstif12, dt (Irix and Solaris only)
# Default: ${MOTIF12_TYPE_DEFAULT}

#MOTIF12_TYPE_DEFAULT?=	lesstif12
# Used by motif.buildlink2.mk as the final default value for MOTIF12_TYPE.
# Possible:  lesstif12, dt (Irix and Solaris only)
# Default: lesstif12, or dt (Irix and Solaris only)

#MPG123_ARM_FIXED64=YES
# Used by mpg123 and mpg123-esound to enable ARM to use 64bit fixedpoint
# Possible: not defined, YES
# Default: not defined

#MTOOLS_ENABLE_FLOPPYD=
# Used by the mtools package to determine whether or not the floppyd
# program is installed. X11 libraries and header files are needed to
# build floppyd and run floppyd.
# Possible: defined, not defined
# Default: not defined

MUTT_USE_NCURSES?= NO
# Force ncurses to be used by mutt. (Older NetBSD and most non-NetBSD
# platforms get it anyway.)
# Possible: YES, NO
# Default: NO

MUTT_USE_SLANG?= NO
# Use slang instead of curses in mutt.
# Possible: YES, NO
# Default: NO

MUTT_USE_SSL?= YES
# Enable SSL in mutt (for pop and imap connections).
# Possible: YES, NO
# Default: YES

#MYSQL_USER?=		mysql
# The username of the mysql administrator.
# Possible: any user name
# Default: mysql

#MYSQL_GROUP?=		mysql
# The group of the mysql administrator.
# Possible: any group name
# Default: mysql

#MYSQL_DATADIR?=	/var/mysql
# Home directory of the mysql administrator and location of the
# database files. 
# Possible: any directory
# Default: /var/mysql

NMH_EDITOR?= vi
# default editor for use in nmh.
# Possible: any editor.
# Default: vi

NMH_MTA?=	smtp
# default MTA for use in nmh.
# Possible: smtp or sendmail.
# Default: smtp

NMH_PAGER?= more
# default pager for use in nmh.
# Possible: any pager.
# Default: more

#NS_PREFERRED=
# Used by netscape to determine preferred browser to open
# Possible: not defined, communicator, navigator, mozilla
# Default: not defined, which implies communicator

#NS_NO_FLASH=
# Used by navigator/communicator package to decide if flash should be
# installed or not. By default, flash is installed.
# Possible: not defined, defined
# Default: not defined

#NS_USE_BSDI=	YES
# Used to decide if i386 BSDi Netscape binary should be used in preference 
# to linux version.
# Possible: not defined, YES
# Default: not defined

#NS_USE_SUNOS=	YES
# Used to decide if sparc SunOS-4.1 Netscape binary should be used in preference 
# to the Solaris-2.5.1 version.
# Possible: not defined, YES
# Default: not defined

OPENSSH_CHROOT?=	/var/chroot/sshd
# The chroot directory for OpenSSH with privilege separation. This directory
# will be created and MUST be only readable by root.
# Possible: any directory
# Default: /var/chroot/sshd

OPENSSH_USER?=		sshd
# The unprivileged user for OpenSSH with privilege separation.
# Possible: any user name
# Default: sshd

OPENSSH_UID?=		16
# The unprivileged UID for OpenSSH with privilege separation.
# Possible: any uid
# Default: 16

OPENSSH_GROUP?=		sshd
# The group of the OPENSSH_USER for OpenSSH with privilege separation.
# Possible: any group name
# Default: sshd

OPENSSH_GID?=		16
# The GID of the OPENSSH_USER for OpenSSH with privilege separation.
# Possible: any gid
# Default: sshd

P4USER?=	perforce
# The unprivileged user for the Perforce server.
# Possible: any user name
# Default: perforce

P4GROUP?=	p4admin
# The group of the P4USER for the Perforce server.
# Possible: any group name
# Default: p4admin

P4ROOT?=	/var/perforce
# The directory where the Perforce server will store its depot.
# Possible: any directory
# Default: /var/perforce

P4PORT?=	1666
# The TCP port on which the Perforce server will listen.
# Possible: any port
# Default: 1666

PALMOS_DEFAULT_SDK?=	3.5
# Version of PalmOS SDK to use as default.
# Possible: 1, 2, 3.1, 3.5
# Default: 3.5

PAPERSIZE?=	A4
# Default paper size for packages.
# Possible: A4, Letter.
# Default: A4

PGGROUP?=	pgsql
# Used in postgresql package as the groupname of the database
# administrator
# Possible: any group name
# Default: pgsql

PGUSER?=	pgsql
# Used in postgresql package as the username of the database admin
# Possible: any user name
# Default: pgsql

PGHOME?=	${PREFIX}/${PGUSER}
# Used in postgresql package as the home directory for the database
# administrator
# Possible: any valid location
# Default: ${PREFIX}/${PGUSER}

#PG_MB_ENCODING=	SQL_ASCII
# Used to postgresql package to define the language encoding of the
# backend server process.
# Possible: SQL_ASCII, EUC_JP, EUC_CN, EUC_KR, EUC_TW, UNICODE, MULE_INTERNAL,
#	LATIN1, LATIN2, LATIN3, LATIN4, LATIN5, KOI8, WIN, ALT
# Default: undefined

PILRC_USE_GTK?=	YES
# Use gtk+ in pilrc, needed for the UI previewer.
# Possible: YES, NO
# Default: YES

#PINE_USE_LDAP=
# Compile code into pine to use a LDAP server for an address book. 
# Possible: undefined, YES
# Default: undefined (support not compiled in)

#PINFO_USE_NATIVE_CURSES=
# Used in pinfo to use NetBSD native curses, rather than ncurses.
# Only works on NetBSD-1.5 and newer.
# Possible: YES, not defined
# Default: not defined

#PKG_JVM=
# Used to choose a java virtual machine for packages which use Java.
# ${JAVA_HOME} will be set based on this choice, if unset
# Possible: jdk, sun-jdk, blackdown-jdk13, kaffe (kaffe currently has some problems)
# Default: jdk on NetBSD/i386, blackdown-jdk13 on powerpc, kaffe elsewhere

PKG_LANG?=english
# Used to specify preferred language settings
# Currently only used by www/netscape7
# Possible: depends on packages supporting this variable, basically any
# language.  Should be '<lang>_<lc>' or '<lang>', for example 'english_uk',
# 'german' or 'portuguese_br'.
# Default: english

#PKGVULNDIR=
# Where audit-packages searchs for the vulnerabilities file.
# Possible: any path
# Default: ${DISTDIR}

#POP_WITH_DRAC=
# Used in the following packages to enable the optional DRAC support:
# teapop
# Possible: defined, not defined
# Default: not defined

#POPTOP_USE_MPPE=
# Used in poptop package to specify the use of the mppe-ppp package
# in preference to the standard ppp
# Possible: defined, not defined
# Default: not defined

#CYRUS_USE_INET6=YES
# Add support for IPv6.
# Possible: YES, not defined
# Default: not defined

#POSTFIX_USE_INET6=YES
# Add support for IPv6.
# Possible: YES, not defined
# Default: not defined

#POSTFIX_USE_LDAP=YES
# Add support for LDAP.
# Possible: YES, not defined
# Default: not defined

#POSTFIX_USE_MYSQL=YES
# Add support for MySQL maps.
# Possible: YES, not defined
# Default: not defined

#POSTFIX_USE_PCRE=YES
# Add support for Perl Compatible Regular Expressions.
# Possible: YES, not defined
# Default: not defined

#POSTFIX_USE_TLS=YES
# Add support for TLS.
# Possible: YES, not defined
# Default: not defined

#POSTFIX_VERP=YES
# Add support for Variable Envelope Return Paths.
# Possible: YES, not defined
# Default: not defined

#PURE_FTPD_USE_MYSQL=YES
# Add support for MySQL.
# Possible: YES, not defined
# Default: not defined

#SAMBA_USE_LDAP=YES
# Add support for LDAP.
# Possible: YES, not defined
# Default: not defined

#SASL_USE_GSSAPI=YES
# Add support for GSSAPI.
# Possible: YES, not defined
# Default: not defined

PRIV_CONF_DIR?=${LOCALBASE}/etc
# Specify the parent of the directory for pkgsrc/security/priv
# package's configuration data.
# Possible: Any valid directory
# Default: ${LOCALBASE}/etc

#PROCMAIL_MAILSPOOLHOME=.MailBox
# To default user mailboxes to their home directory,
# specify the name of the mailbox file.
# Possible: Any valid filename, not defined
# Default: not defined

PROCMAIL_TRUSTED_IDS?=0
# To allow all users to use the "-f" switch set this to 0.
# Possible: A list of users, terminated by a zero.
# Default: see Makefile

.if exists(/usr/bin/ssh)
PVM_SSH?=	/usr/bin/ssh
.else
PVM_SSH?=	${LOCALBASE}/bin/ssh
.endif
# Specify the rsh/ssh program used by pvm to communicate between
# systems.
# Possible:  Any rsh/ssh program.
# Default:   /usr/bin/ssh if it exists, otherwise ${LOCALBASE}/bin/ssh

QMAILDIR?=	/var/qmail
# Specify the directory for qmail installation
# Possible: any valid location
# Default: /var/qmail

QPOPPER_FAC?= LOCAL1
# Used by qpopper package as the default syslog facility.
# Possible: syslog(3)'s facility string without preceding "LOG_".
# Default: LOCAL1

QPOPPER_USER?= pop
# Used by qpopper package as the owner of apop database and qpopauth
# command runs at.
# Possible: any
# Default: pop

#QPOPPER_SERVERMODE=
# Used in qpopper package to enable server mode.
# Possible: defined, not defined
# Default: not defined

RASMOL_DEPTH?= 8
# Used in rasmol package to choose display depth to compile the package
# for, since it only supports one at a time.
# Possible: 8, 16, 32
# Default: 8

RPM_DB_PREFIX?=	/var/pkg
# Used in the rpm package to note the prefix of the path to the RPM
# databases.  The RPM databases are stored in ${RPM_DB_PREFIX}/lib/rpm.
# Possible: any valid location, e.g. ${LOCALBASE}
# Default: /var/pkg

#SAWFISH_THEMES=
# Specifies the DISTFILES for wm/sawfish-themes, to allow the user to choose
# which themes to install
# Possible: empty, any number of theme-name-[0-9]*.*.tar.gz
# Default: Set to include about 180 themes available on themes.freshmeat.net

#SDL_USE_NAS=
# Used in SDL package to enable use of the network audio system
# Possible: defined, not defined
# Default: not defined

SDIST_PAWD?= pwd
# If you are using amd you'll want to use pawd instead of pwd to derive
# the current working directory.
# Possible: pawd, pwd
# Default: pwd

#SERIAL_DEVICES=
# Used to provide a default setting for all the serial devices for
# various packages which communicate over the serial port.
# Possible:  /dev/your_favorite_serial_device0 /dev/your_favorite_serial_device1 ...
# Default: defaults for various machine_archs are set in mk/bsd.prefs.mk

#SILC_CLIENT_WITH_PERL?=  no
# Used to decide whether perl scripting support will be compiled.
# Possible: YES, NO
# Default: YES

#SPARC_TARGET_ARCH= sparcv7
# Select SPARC target architecture under Solaris.
# Possible: sparcv7, sparcv8 or sparcv9.
# Default: sparcv7

#SPOP3D_ENABLE_APOP= yes
# Enable APOP support in the mail/solid-pop3d package.
# Possible: undefined, defined
# Default: undefined

#SPOP3D_ENABLE_STANDALONE= yes
# Build mail/solid-pop3d to run standalone instead of via inetd.
# Possible: undefined, defined
# Default: undefined 

#SPOP3D_ENABLE_ALIASES= yes
# Build mail/solid-pop3d with support for user names mapping and non-IP
# based virtuals.
# Possible: undefined, defined
# Default: undefined

#SQUID_CONFIGURE_ARGS=
# Used in squid package to set build configuration options.
# Possible: see "configure --help"
# Default: --enable-cachemgr-hostname=localhost
#          --enable-icmp
#          --enable-ipf-transparent
#          --enable-snmp

SSH_RSHPATH?= /usr/bin/rsh
# Used in ssh to specify standard rsh path
# Possible: path to rsh binary
# Default: /usr/bin/rsh

SSH_SUID?= NO
# Used in ssh to enable setuid installation of "ssh" binary.
# Possible: YES, or NO.
# Default: NO

SSYNC_PAWD?= pwd
# If you are using amd you'll want to use pawd instead of pwd to derive
# the current working directory.
# Possible: pawd, pwd
# Default: pwd

TIN_USE_INN_SPOOL?= NO
# Used to enable reading directly in an inn spool.
# Possible: YES, or NO.
# Default: NO

#TEAPOP_WITHOUT_VPOP=
# Compile teapop without virtual domain support
# Possible: defined, not defined
# Default: not defined

#TEAPOP_WITHOUT_APOP=
# Compile teapop without apop support
# Possible: defined, not defined
# Default: not defined

#TEAPOP_WITH_MYSQL=	yes
# Compile teapop with MySQL support.
# Possible: defined, not defined
# Default: not defined

#TEXMFSITE=
# Used in TeXfamily package which depends on teTeX package to specify
# site-local texmf configuration.
# Since teTeX package uses ${PREFIX}/share/texmf directory, TeXfamily
# package uses ${PREFIX}/share/texmf.local.  Therefore, though you can
# use /usr/local/share/texmf as TEXMFSITE, it causes a conflict if you
# set ${PREFIX} to /usr/local.  Use another path in such a case.
# Possible: any valid path
# Default: none

TKPASMAN_USE_SSL?=	YES
# Enable SSL in tkpasman (to encode stored passwords)
# Possible: YES, NO
# Default: YES

USE_CANNA?= YES
# Used in kinput2 and nvi-m17n to enable Canna kana-kanji converter
# support.
# Possible: YES, or NO.
# Default: YES

USE_CRYPTO?=	YES
# Used in speakfreely to choose support for encrypted connections.
# Possible: YES, or NO.
# Default: YES

#USE_CUPS= YES
# Used by packages to compile in support for the UNIX IPP implementation, CUPS.
# Possible: YES, not defined
# Default: not defined

USE_DB2?= NO
# Used in sendmail to build with database library 2.x from the db package.
# Possible: YES, or NO.
# Default: NO

#USE_GIF=
# Enable GIF support in qt1.  (disabled per default due to licensing
# problems; future revisions might have no support at all)
# Also used by tiff-library to enable LZW compression support.
# Possible: defined, not defined
# Default: not defined

USE_I586?=	NO
# Use assembler routines optimized for i586 in gnupg.
# Possible: YES, or NO.
# Default: NO

USE_IDEA?=	NO
# Used in gnupg, speakfreely, and ssh to choose whether to compile using
# the patented IDEA encryption algorithm.
# Possible: YES, or NO.
# Default: package-dependent

#USE_INET6=
# Enable IPv6 support on certain packages.  It is safer to leave it undefined
# in mk.conf and obey the default.  Reasons:
# - it is just fine to use IPv6-ready packages on top of non-IPv6 kernel
#   (assuming that you have IPv6-ready headers and libraries)
# - it may cause some trouble to use a package compiled with USE_INET6=NO,
#   on top of IPv6-ready kernel
# Possible: not defined, NO, YES
# Default: YES on IPv6-ready userland, not defined otherwise

#USE_INN=
# Used in nn and trn to specify use of "inn" instead of "nntpclnt"
# package to provide "inews" binary.
# Possible: not defined, YES
# Default: not defined

USE_MMX?=	NO
# Used in eterm, imlib2, libast, and snes9x to specify if the i386 MMX
# extensions should be used.
# Possible: YES, NO
# Default: NO

USE_OPENLDAP?=	NO
# Enable openldap support in gnupg.
# Possible: YES, or NO.
# Default: NO

#USE_OSS=
#
# Used to enable OSS audio support in preference to or in place of Sun audio
# support in various packages.
# Possible: defined, not defined
# Default: not defined

#USE_PAM=
# Used to specify optional support for PAM authentication
# Possible: defined, not defined
# Default: not defined

#USE_RSAREF2=
# Used in openssl to specify use of the RSA reference package instead of
# the built-in code for the RSA algorithm. (Not recommended!)
# Possible: YES, or NO.
# Default: not defined.

#USE_SASL=YES
# Used to specify optional support for SASL authentication
# Possible: YES, not defined
# Default: not defined

USE_SJ3?= YES
# Used in kinput2 to enable SJ3 kana-kanji converter support.
# Possible: YES, or NO.
# Default: YES

#USE_SOCKS=
# Used to specify SOCKS firewall support
# Set this to the version of socks necessary.
# Possible: 4, 5, not defined
# Default: not defined

USE_WNN4?= YES
# Used in kinput2 to enable FreeWnn (a.k.a.  Wnn4) kana-kanji
# converter support.
# Possible: YES, or NO.
# Default: YES

#USE_XFACE=
# Used in xemacs package to build in support for xface
# (pkgsrc/mail/face)
# Possible: not defined, YES
# Default: not defined

USERPPP_GROUP?=	network
# Used in the userppp package to specify the default group.
# Possible: any group name
# Default: network

#VIM_EXTRA_OPTS=
# Used in vim package to build with non-gui extra options
# Possible: not defined, see "configure --help"
# Default: not defined

W3M_USE_COLOR?=                 YES
# Used in w3m to use colors.
# Possible: YES, NO
# Default: YES

W3M_USE_COOKIE?=                YES
# Enable cookie support in w3m.
# Possible: YES, NO
# Default: YES

W3M_USE_IMAGE?=			NO
# Enable inline image display support in w3m.  (Useful, but still a bit
# buggy yet?)
# Possible: YES, NO
# Default: NO

W3M_USE_JAPANESE_MESSAGES?=     NO
# Let w3m to use Japanese messages. (Japanese localization.)
# Possible: YES, NO
# Default: NO

W3M_USE_LYNX_KEY?=              NO
# Enable lynx like keybinding for w3m.
# Possible: YES, NO
# Default: NO

W3M_USE_M17N=                   YES
# For multilingual support for w3m.
# Possible: YES, NO
# Default: YES

W3M_USE_MOUSE?=                 YES
# Enable mouse support in w3m.
# Possible: YES, NO
# Default: YES

W3M_USE_SSL?=                   YES
# Enable HTTPS support in w3m.
# Possible: YES, NO
# Default: YES

W3M_USE_UNICODE?=               YES
# Used in w3m to use Unicode characters.
# Possible: YES, NO
# Default: YES

WGET_USE_SSL?=	YES
# Enable SSL in wget (for https connections)
# Possible: YES, NO
# Default: YES

#WDM_MANAGERS?=
# Is a space-separated list of window managers for x11/wdm to support.
# Possible: any space-separated list of window managers
# Default: not defined

WINDOWMAKER_OPTIONS?= gnome kde openlook
# Options for building windowmaker package. Used to add support for
# GNOME, KDE or OPEN LOOK(tm) and to avoid redundancies with KDE.
# Possible: gnome, kde, openlook, lite
# Default: gnome kde openlook

WINDOWMAKER_THEMES?=	FreeBSD-theme
# Used in wm-themes package to specify the themes which will be
# installed.
# Possible: see http://wm.themes.org/
# Default: FreeBSD-theme

XAW_TYPE?=standard
# Used in various packages to specify that libXaw is used.
# Possible: standard, 3d, xpm
# Default: standard

XCHAT_USE_SSL?=	YES
# Enable SSL in xchat (for IRC server connections)
# Possible: YES, NO
# Default: YES

#XLOCK_DEFAULT_MODE=
# Set the default display (screen saver) mode for xlockmore.
# Possible: ant, apollonian, ball, bat, blank, blot, bomb, bouboule, bounce,
#           braid, bubble, bug, clock, coral, crystal, daisy, dclock, decay,
#           deco, demon, dilemma, discrete, dragon, drift, euler2d, eyes,
#           fadeplot, flag, flame, flow, forest, galaxy, goop, grav, helix,
#           hop, hyper, ico, ifs, image, juggle, julia, kaleid, kumppa, laser,
#           life, life1d, life3d, lightning, lisa, lissie, loop, lyapunov,
#           mandelbrot, marquee, matrix, maze, mountain, munch, nose, pacman,
#           penrose, petal, petri, polyominoes, puzzle, pyro, qix, random,
#           roll, rotor, scooter, shape, sierpinski, slip, solitare, space,
#           sphere, spiral, spline, star, starfish, strange, swarm, swirl,
#           t3d, tetris, thornbird, tik_tak, triangle, tube, turtle, vines,
#           voters, wator, wire, world, worm, xcl, xjack, not defined
# Default: not defined

#XLOCK_LIGHT=
# Used to build xlockmore without support for GL True Text, Motif, OpenGL,
# Mesa 3D libraries and XPM pixmaps.
# Possible: defined, not defined
# Default: not defined

#ZIP_ENCRYPTION=
# Add encryption code to zip1
# Possible: defined, not defined
# Default: not defined

#ZSH_STATIC=
# Build statically linked zsh binary - recommended if used as a login shell
# Possible: defined, not defined
# Default: not defined


#
#	Overrides for faster or cheaper sites.
#
#	Refer to http://www.netbsd.org/Sites/net.html or /usr/doc/MIRRORS
#	for information on determining the location of NetBSD mirror sites.
#

# Australia.
#
#MASTER_SITE_GNOME=	ftp://www.planetmirror.com.au/pub/GNOME/
#MASTER_SITE_GNU=	ftp://www.planetmirror.com.au/pub/gnu/
#MASTER_SITE_MOZILLA=	ftp://www.planetmirror.com.au/pub/mozilla/releases/
#MASTER_SITE_PERL_CPAN=	ftp://www.planetmirror.com.au/pub/perl/CPAN/modules/by-module/
#MASTER_SITE_SUNSITE=	ftp://www.planetmirror.com.au/pub/sunsite/
#MASTER_SITE_SUSE=	ftp://www.planetmirror.com.au/pub/suse/i386/${SUSE_VERSION}/suse/
#MASTER_SITE_TEX_CTAN=	ftp://www.planetmirror.com.au/pub/tex-archive/
#MASTER_SITE_SOURCEFORGE=ftp://www.planetmirror.com.au/pub/sourceforge/
#MASTER_SITE_XCONTRIB=	ftp://www.planetmirror.com.au/pub/X11/contrib/
#MASTER_SITE_BACKUP=	ftp://ftp.au.netbsd.org/pub/NetBSD/packages/distfiles/ \
#			ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/
#MASTER_SITE_LOCAL=	ftp://ftp.au.netbsd.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/ \
#			ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/
#

# Austria
#
#MASTER_SITE_XCONTRIB=	ftp://ftp.at.netbsd.org/hci/X11/x.org/contrib/
#MASTER_SITE_GNU=	ftp://ftp.at.netbsd.org/gnu/gnusrc/
#MASTER_SITE_PERL_CPAN=	ftp://ftp.at.netbsd.org/languages/perl/CPAN/modules/by-module/
#MASTER_SITE_TEX_CTAN=	ftp://ftp.at.netbsd.org/publishing/tex/CTAN/
#MASTER_SITE_SUNSITE=	ftp://ftp.univie.ac.at/systems/linux/sunsite/
#MASTER_SITE_BACKUP=	ftp://ftp.at.netbsd.org/opsys/NetBSD/packages/distfiles/

# Denmark
#
#MASTER_SITE_GNU=	ftp://ftp.sunsite.auc.dk/pub/gnu/
#MASTER_SITE_PERL_CPAN=	ftp://ftp.sunsite.auc.dk/pub/languages/perl/CPAN/modules/by-module/
#MASTER_SITE_TEX_CTAN=	ftp://ftp.sunsite.auc.dk/pub/tex/ctan/
#MASTER_SITE_SUNSITE=	ftp://ftp.sunsite.auc.dk/mirrors/sunsite.unc.edu/pub/Linux/
#MASTER_SITE_BACKUP=	ftp://ftp.dk.netbsd.org/pub/NetBSD/packages/distfiles/

# Finland
#
#MASTER_SITE_XCONTRIB=	ftp://ftp.funet.fi/pub/X11/contrib/
#MASTER_SITE_GNU= 	ftp://ftp.funet.fi/pub/gnu/gnu/
#MASTER_SITE_PERL_CPAN=	\
#	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/
#MASTER_SITE_TEX_CTAN=	ftp://ftp.funet.fi/pub/TeX/CTAN/
#MASTER_SITE_SUNSITE=	\
#	ftp://ftp.funet.fi/pub/mirrors/sunsite.unc.edu/pub/Linux/
#MASTER_SITE_BACKUP=	\
#	ftp://ftp.fi.netbsd.org/pub/NetBSD/packages/distfiles/

# Japan
#
#MASTER_SITE_XCONTRIB=	ftp://ftp.ring.gr.jp/pub/X/opengroup/contrib/
#MASTER_SITE_GNOME=	ftp://ftp.ring.gr.jp/pub/X/gnome/
#MASTER_SITE_GNU=	ftp://ftp.ring.gr.jp/pub/GNU/
#MASTER_SITE_MOZILLA=	ftp://ftp.ring.gr.jp/pub/net/www/mozilla/mozilla/releases/
#MASTER_SITE_PERL_CPAN=	ftp://ftp.ring.gr.jp/pub/lang/perl/CPAN/modules/by-module/
#MASTER_SITE_TEX_CTAN=	ftp://ftp.ring.gr.jp/pub/text/CTAN/
#MASTER_SITE_SUNSITE=	ftp://sunsite.sut.ac.jp/pub/archives/linux/sunsite-unc/
#MASTER_SITE_BACKUP=	\
#	ftp://ftp.ring.gr.jp/pub/NetBSD/packages/distfiles/ \
#	ftp://ftp.jp.netbsd.org/pub/NetBSD/packages/distfiles/

# United Kingdom
#
#MASTER_SITE_XCONTRIB=	ftp://sunsite.org.uk/Mirrors/ftp.x.org/contrib/
#MASTER_SITE_GNU=	ftp://sunsite.org.uk/packages/gnu/
#MASTER_SITE_PERL_CPAN=	ftp://sunsite.org.uk/packages/perl/CPAN/modules/by-module/
#MASTER_SITE_TEX_CTAN=	ftp://sunsite.org.uk/packages/tex/uk-tex/
#MASTER_SITE_SUNSITE=	ftp://sunsite.org.uk/Mirrors/sunsite.unc.edu/pub/Linux/
#MASTER_SITE_BACKUP=	ftp://sunsite.org.uk/packages/NetBSD/packages/distfiles/ \
#	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/
# France. This will try to fetch distfile from the distfile mirror
# before trying ${MASTER_SITE} or the distfiles at ftp.netbsd.org
#MASTER_SITE_OVERRIDE= \
#	ftp://ftp2.fr.netbsd.org/pub/NetBSD/packages/distfiles/
#MASTER_SITE_BACKUP=     \
#	ftp://ftp2.fr.netbsd.org/pub/NetBSD/packages/distfiles/
#MASTER_SITE_LOCAL=      \
#	ftp://ftp.fr.netbsd.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

.if exists(${.CURDIR}/../../mk/bsd.pkg.obsolete.mk)
.include "${.CURDIR}/../../mk/bsd.pkg.obsolete.mk"
.elif exists(${.CURDIR}/../mk/bsd.pkg.obsolete.mk)
.include "${.CURDIR}/../mk/bsd.pkg.obsolete.mk"
.elif exists(${.CURDIR}/mk/bsd.pkg.obsolete.mk)
.include "${.CURDIR}/mk/bsd.pkg.obsolete.mk"
.endif
