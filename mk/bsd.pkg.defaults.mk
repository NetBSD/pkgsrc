# $NetBSD: bsd.pkg.defaults.mk,v 1.232 2004/04/21 17:08:06 tv Exp $
#

# A file providing defaults for pkgsrc and the packages collection.
# See the NetBSD mk.conf(5) and packages(7) manual page for a full
# description of all available options.
#

# ************************************************************************
# NOTE TO PEOPLE EDITING THIS FILE - USE LEADING SPACES, NOT LEADING TABS.
# ************************************************************************

#ALLOW_VULNERABLE_PACKAGES=
# allow the user to build packages which are known to be vulnerable to
# security exploits
# Possible: defined, not defined
# Default: not defined

MANINSTALL?= maninstall catinstall
# Specify manpage installation types.
# Possible: maninstall, catinstall, both types or empty
# Default: maninstall catinstall

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

#ABI=	
# The ABI to be used, if supported by the Operating System and/or compiler.
# Currently only used under IRIX and explicitly set during bootstrapping
# Only change this if you really know what you're doing -- libraries of
# one ABI can not be linked with libraries of another!
# Possible: 64 (64 bit ABI), 32 (SGI's N32 ABI), undefined (SGI's old o32 ABI)
# Default: determined during bootstrapping

#PKG_DEVELOPER=	yes
# Run a sanity check that package developers want:
#  * run check-shlibs to see that all binaries will find their libs
# Possible: defined, not defined
# Default: not defined

IGNORE_RECOMMENDED?=	no
# Ignore package prerequisite recommendations.  If this is set to
# "no", all entries in RECOMMENDED will be added to DEPENDS.
# If set to "yes", a warning will be printed if recommendations
# are possibly ignored.
#
# WARNING: This should only be set if you know what you're doing.
# Please read pkgsrc/Packages.txt for details.
#
# Possible: yes, no
# Default: no

#PKG_REGISTER_SHELLS= YES
# Automatically register shells in /etc/shells
# Possible: YES, NO
# Default: YES

PKGSRC_MESSAGE_RECIPIENTS?=
# login names of recipients of any MESSAGE files which will be mailed
# Possible: any login names
# Default: none

PKGSRC_SHOW_BUILD_DEFS?=yes
# Show BUILD_DEFS definitions for a package when it is being built
# (BUILD_DEFS are extra definitions which govern how some packages are
# built and behave)
# Possible: "yes", not "yes"
# Default: "yes"

PKGSRC_RUN_TEST?=	no
# Run test target before install
# Possible: yes, no
# Default: no

PREFER_PKGSRC?=		MesaLib Xft2 Xrandr Xrender expat fontconfig	\
			freetype2 glu randrext render xcursor
PREFER_NATIVE?=		yes
#
# When building packages, whether to prefer the pkgsrc or native
# versions of software that's also part of the base system.  Its value
# can be either yes/no, or a list of packages as named in the
# BUILDLINK_PACKAGES line in a package's buildlink[23].mk file.
# Preferences are determined by the most specific instance of the
# package in either PREFER_PKGSRC or PREFER_NATIVE.  If a package is
# specified in neither or in both variables, then PREFER_PKGSRC has
# precedence over PREFER_NATIVE.
#
# Possible: yes, no, or a list of packages

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
# Default: /usr/X11R6, /usr/openwin for Solaris

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

USE_XPKGWEDGE?=	yes
# Whether we should use xpkgwedge or not to install all packages into
# ${LOCALBASE}.
# Possible: yes, no
# Default: yes

BSDSRCDIR?=	/usr/src
# Where the NetBSD src module source tree is located
#  used in the emulators/plex86, emulators/vmware-module{,3}, net/arla,
#  sysutils/aperture, and sysutils/fdgw packages
# Possible: any path
# Default: /usr/src

BSDXSRCDIR?=	/usr/xsrc
# Where the NetBSD xsrc module source tree is located
#  used in the x11/xservers package
# Possible: any path
# Default: /usr/xsrc

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

DEFAULT_VIEW?= ""
# This is the default view to which packages are added after installation.
# Default: "" (the empty view)

PKG_INSTALLATION_PREFS?= overwrite pkgviews
# This is a whitespace-separated list of installation types to try when
# building a package, in order of preference.
# Possible: any of: overwrite, pkgviews
# Default: overwrite pkgviews

PKG_SYSCONFBASE?= ${PREFIX}/etc
# This is the main config directory under which all package configuration
# files should be found.
# Possible: any path you like
# Default: ${PREFIX}/etc

RCD_SCRIPTS_DIR?= /etc/rc.d
# This is the system rc.d script directory in which all rc.d scripts
# expected to be executed at boot-time should be found.  Package views
# users may want to set this to "${PKG_SYSCONFBASEDIR}/rc.d".
# Possible: any path you like
# Default: /etc/rc.d

PACKAGES?=	${_PKGSRCDIR}/packages
# Store generated packages on a per-architecture base
# Possible: any path you like
# Default: /usr/pkgsrc/packages

PKGVULNDIR?=	${DISTDIR}
# Specifies where the `vulnerabilities' file is located.  This variable
# is used by the audit-packages program and by pkgsrc itself to do security
# checks before building/installing programs.
# Possible: any path you like
# Default: /usr/pkgsrc/distfiles

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
#ACCEPTABLE_LICENSES+=	fprot-workstation-license
# Enable it if you accept the license for fprot-workstation-bin and would
# like to build the package.  see pkgsrc/licenses/fprot-workstation-license
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
#ACCEPTABLE_LICENSES+=	webwasher-license
# Enable it if you accept the license terms for webwasher and would
# like to build webwasher.  see pkgsrc/licenses/webwasher-license
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

#MASTER_SORT=	.ac.at .at .de .ch .se .fi .no
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

#IMAKE?=	${X11BASE}/bin/imake ${IMAKEOPTS}
# The imake binary to invoke.
# Possible: any path followed by any valid flags
# Default: ${X11BASE}/bin/imake ${IMAKEOPTS}

#IMAKEOPTS=
# Options passed to imake(1).  The defaults ensure that imake finds the
# correct commands.
# Possible: any valid flags
# Default:
#  for Solaris with gcc:
#	-DHasGcc2=YES -DHasGcc2ForCplusplus=YES
#  for IRIX:
#	-DMakeCmd=${PREFIX}/bin/bmake -DProjectRoot=${X11BASE} \
#	-DManUsr=${PREFIX}
.if ${OPSYS} == "IRIX"
#IMAKEOPTS?=	-DMakeCmd=${PREFIX}/bin/bmake -DProjectRoot=${X11BASE} \
#		-DManUsr=${PREFIX}
# ABI specific flags may be added during bootstrapping process or by hand:
.  if defined(ABI)
.    if ${ABI} == "32"
#IMAKEOPTS+=	-DBuildN32
.    else
#IMAKEOPTS+=	-DBuild64bit
.    endif
.  endif
# you may also wish to add ISA specific flags, such as "-DSgiISA32=4" if
# you are compiling for mips4.
.elif ${OPSYS} == "SunOS"
# The flags required by imake with gcc on Solaris are automatically
# added if gcc is being used. Though it should not be needed, you can
# override this using:
#IMAKEOPTS+=	-DHasGcc2=YES -DHasGcc2ForCplusplus=YES
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
# Whitespace separated list of URLs for binary packages. Directories
# "All" etc. are expected in the named place, variables "rel" and
# "arch" are replaced with OS release ("1.5", ...) and architecture
# ("mipsel", ...)
# Possible: any ftp url, see above.
# Default: ftp://ftp.NetBSD.org/pub/NetBSD/packages/$${rel}/$${arch}

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

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "powerpc"
APR_USE_DB4?= NO
.else
APR_USE_DB4?= YES
.endif
# Used in apr to determine whether to use db4.  This should be the
# default, but apr is broken on NetBSD/powerpc so it is disabled
# there.
# Default: YES

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

#BITCHX_WITH_GTK=
# Used in bitchx to determine whether to include support for GTK,
# for a GUI client.
# Possible: not defined, YES
# Default: not defined

#BLENDER_INSTALL_DOC=	YES
# Used in blender to determine if the extensive html documentation should be
# installed or not.
# Possible: YES, not defined
# Default: not defined

#BLENDER_USE_OGG=	YES
# Used in blender to determine if support for the ogg audio format should be
# compiled in or not.
# Possible: YES, not defined
# Default: not defined

#BLENDER_USE_VORBIS=	YES
# Used in blender to determine if support for the vorbis audio format should
# be compiled in or not.
# Possible: YES, not defined
# Default: not defined

#BLENDER_USE_OPENAL=	YES
# Used in blender to determine if support for the openal audio format should
# be compiled in or not.
# Possible: YES, not defined
# Default: not defined

#BLENDER_USE_EXPPYTHON= YES
# Used in blender to determine if experimental python support should be
# compiled in or not.
# Possible: YES, not defined
# Default: not defined

#BULK_PREREQ=
# Used during bulk package builds.  Packages listed in this variable are
# assumed to be required to build all packages.  Only a very limited number
# of packages belong in this variable.  An example of an appropriate package
# is pkgtools/xpkgwedge.  Currently pkgtools/digest is always added to this
# list.
# Possible: category/pkg
# Default: not defined

CANNA_GROUP?=	daemon
# Used in the canna-server-bin package to specify the server group.
# Possible: any group name
# Default: daemon

CANNA_USER?=	daemon
# Used in the canna-server-bin package to specify the server user.
# Possible: any user name
# Default: daemon

#CDRECORD_CONF= ${PKG_SYSCONFDIR}/cdrecord.conf
# The location of the cdrtools/cdrecord configuration file. The
# sysutils/cdrecord pkg issues a warning if the cdrtools default of
# /etc/default/cdrecord is changed, and the man pages are updated
# accordingly. This is required by the cdrtools license.
# Possible: any file name
# Default: ${PKG_SYSCONFDIR}/cdrecord.conf

CLAMAV_GROUP?=	clamav
# Used in clamav to specify the group to run clamav
# Possible: any group name
# Default: clamav

CLAMAV_USER?=	clamav
# Used in clamav to specify the user to run clamav
# Possible: any user name
# Default: clamav

CUE_USE_CANNA?=	NO
# Used by cue package to determine whether to enable Canna support.
# Possible: YES, NO
# Default: NO

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

DOVECOT_USE_GNUTLS?=	NO
# Used by dovecot package to determine whether to use GnuTLS or OpenSSL as the
# underlying crypto library.
# Possible: YES, NO
# Default: NO

DOVECOT_USE_PGSQL?=	NO
# Used by dovecot package to determine whether to enable PostgreSQL support.
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

EMACS_TYPE?=	emacs21
# Used by emacs.mk to determine which emacs version should be installed and
# emacs lisp packages should be built for.
# Possible: emacs21, emacs21nox, emacs20, xemacs214, xemacs215
# Default: emacs21

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

EMACS_USE_XAW3D?= NO
# Used by emacs package to determine if should use Xaw3D for the scrollbar.
# Possible: YES, NO
# Default: NO

EXIM_GROUP?=	mail
# Used in the exim package to specify the server group.
# Possible: any group name
# Default: mail

EXIM_USER?=	mail
# Used in the exim package to specify the server user.
# Possible: any user name
# Default: mail

FETCHMAIL_USE_SSL?=	YES
# Enable SSL in fetchmail (for pop and imap connections)
# Possible: YES, NO
# Default: YES

FLOW_TOOLS_USE_MYSQL?=	NO
# Used by flow-tools to enable support of flow records export
# into a MySQL database.
# Possible: YES, NO
# Default: NO

#FLUXBOX_USE_XINERAMA?=	NO
# Compile flukebox with xinerama extensions
# Possible: YES, NO
# Default: NO

#FLUXBOX_USE_KDE?=	NO
# Compile flukebox with KDE support
# Possible: YES, NO
# Default: NO

#FLUXBOX_USE_GNOME?=	NO
# Compile flukebox with GNOME support
# Possible: YES, NO
# Default: NO

#FLUXBOX_USE_XFT?=	YES
# Compile flukebox with Xft support
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

GOLEM_WITH_SOUND?=	NO
# Used by golem package to determine whether to enable sound support.
# Possible: YES, NO
# Default: NO

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

#GRUB_PRESET_COMMAND=
# Specifies a single command that will be embedded into GRUB's stage2 and
# executed at boot time as a default configuration file.  This is usually
# useful to create stage2 files with automated diskless support; you should
# set this variable to "bootp", "dhcp" or "rarp", and use it together
# GRUB_NETWORK_CARDS.
# Default: not defined

#GRUB_SCAN_ARGS=
# Can be used to supply additional configure arguments for netboot support in
# GRUB. Set e.g. "GRUB_NETWORK_CARDS" to "ne" and "GRUB_SCAN_ARGS" to
# "--enable-ne-scan=0x300" to let the boot loader search for an NE 2000 ISA
# card at I/O offset 0x300.
# Default: not defined

ICECAST_CHROOTDIR?=	  /var/chroot/icecast
# Used in icecast2 to specify the chroot directory in which icecast
# will be allowed to work.
# Possible: Any valid directory
# Default: /var/chroot/icecast

#ICECAST_CHUNKLEN=512
# If you want a larger backlog for each client, which will allow for
# worse network congestion or other network errors before kicking the
# client, increase the ICECAST_CHUNKLEN value.
# Default: 64

#ICECAST_SOURCE_BUFFSIZE=8192
# SOURCE_BUFFSIZE sets how many bytes will be read from the source
# before trying to send this chunk to the clients. If your server will
# take on a lot of listeners, or stream very high bitrate mpeg data,
# like video mpeg streams, and if you system supports it, you should
# increase this value to 65535 or something similar.
# Default: 8192

IMAP_UW_CCLIENT_MBOX_FMT?=	unix
# Used in imap-uw to set the default format used by c-client programs for
# new mailbox creation.  Check the UW IMAP documentation for more details
# regarding the pros and cons of the various mailbox formats.
#
# Possible: mbox, mbx, mh, mmdf, mtx, mx, news, phile, tenex, unix
# Default: unix

#IMAP_UW_MAILSPOOLHOME=.MailBox
# To default user mailboxes to their home directory,
# specify the name of the mailbox file.
# Possible: Any valid filename, not defined
# Default: not defined

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

IRCD_HYBRID_USE_LOGFILE?=	YES
# Used by ircd-hybrid. Specify if the daemon should use a logfile.
# Note: can be used even when IRCD_HYBRID_USE_SYSLOG is "YES".
# Possible: YES, NO
# Default: YES
 
IRCD_HYBRID_USE_SYSLOG?=	NO
# Used by ircd-hybrid. Specify if the daemon should use syslog.
# Note: can be used even when IRCD_HYBRID_USE_LOGFILE is "YES".
# Possible: YES, NO
# Default: NO

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

IRSSI_USE_SSL?=	YES
# Enable SSL in irssi (for IRC server connections)
# Possible: YES, NO
# Default: YES

#XLOCK_DEFAULT_MODE=
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

JABBERD_USER?= jabberd
# Used in jabberd to specify the user used to run the daemon.
# Possible: any valid username
# Default: jabberd

JABBERD_GROUP?=	jabberd
# Used in jabberd to specify the group userd to run the daemon.
# Possible: any valid group
# Default: jabberd

JABBERD_LOGDIR?= /var/log/jabberd
# Used in jabberd to specify the default directory under which log
# files are placed.
# Possible: any directory
# Default: /var/log/jabberd

JABBERD_SPOOLDIR?= /var/spool/jabberd
# Used in jabberd to specify the default directory under which server
# information is stored.
# Possible: any directory
# Default: /var/spool/jabberd

JABBERD_PIDDIR?= /var/run/jabberd
# Used in jabberd to specify the default directory under which pid
# files are placed.
# Possible: any directory
# Default: /var/run/jabberd

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

KERBEROS_PREFIX_CMDS?=	no
# Use in the Kerberos packages to determine whether to prefix certain
# application executables with a "k".
# Possible: yes, no
# Default: no

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
	af ar bg br ca cs cy da de el en eo es et eu fi fo fr ga gl	\
	he hr hu hy id is it ja ka kl ko lo lt lv nl no oc pl pt ro	\
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
# Used mostly by packages (e.g.:  gnupg, pgp2, ssh) which have fast
# 68020/030/040 assembler routines for multiprecision arithmetic
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

#MAKEINFO_ARGS?=
# flags to be passed to makeinfo(1), if any.  Warning: only use if you
# know what you're doing, may break PLISTs.
# Possible: any valid flag for makeinfo(1)
# Default: may set info files size for consistency across platforms and
# makeinfo version, also various machine_archs arguments may be set in
# mk/defs.${OPSYS}.mk with the _OPSYS_MAKEINFO_ARGS variable.

MKTTINTERP?= no
# Used by freetype2 to enable the TrueType bytecode interpreter.
# Since there are important patent issues related to the to
# use of the interpreter, default to no.
# See http://www.freetype.org/patents.html for details.
# Possible: yes, no
# Default: no

#MOZILLA_USE_LINUX=
# Used by mozilla binary packages to prefer the use of Linux
# compatibility instead of native builds.
# Possible: set, unset
# Default: unset

MOZILLA_USE_XFT?=	NO
# Used by mozilla packages to enable Xft support where available.
# The mozilla-gtk2 package sets this value to YES unconditionally.
# Possible: YES, NO
# Default: NO

MPLAYER_DISABLE_DRIVERS?=
# Whitespace separated list of output drivers that are not wanted in
# mplayer/gmplayer's binary.
# Possible: arts esd matroska nas sdl
# Default: empty

MPLAYER_ENABLE_RUNTIME_CPU_DETECTION?= YES
# Used by mplayer to enable runtime CPU detection -- this makes
# binary packages work on different machines than the one compiled one,
# but may be slower.
# Note that this only takes effect on i386 and that binary packages made with
# this option set to NO will only run reliably on a machine of the same
# CPU type.
# Possible: YES, NO
# Default: YES

MPLAYER_USE_MEDIALIB?= NO
# Used by mplayer to enable optional support for Sun mediaLib library.
# Note that this only takes effect on Solaris.
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

MTOOLS_ENABLE_FLOPPYD?=	NO
# Used by the mtools package to determine whether or not the floppyd
# program is installed. X11 libraries and header files are needed to
# build floppyd and run floppyd.
# Possible: YES, NO
# Default: NO

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

#MYSQL_CHARSET=		latin1
# default character set of mysql.
# Possible: big5, cp1251, cp1257, croat, czech, danish, dec8, dos, estonia,
#	    euc_kr, gb2312, gbk, german1, greek, hebrew, hp8, hungarian,
#	    koi8_ru, koi8_ukr, latin1, latin2, latin5, swe7, usa7, win1250,
#	    win1251ukr, ujis, sjis and tis620
# Default: latin1

#MYSQL_EXTRA_CHARSET=	all
# additional charsets to be compiled in mysql.
# Possible: none, compolex, all or list selected from MYSQL_CHARSET's
#	    possible values.

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

PGSQL_USE_HIER?=	no
# Add support for hierarchical queries with Oracle like CONNECT BY syntax
# to the PostgreSQL 7.4 package.
# See http://gppl.terminal.ru/README.html for details.
# Possible: yes, no
# Default: no

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

PKG_INSTALLATION_TYPES?= overwrite
# This is a whitespace-separated list of installation types supported
# by the package.
#
# *NOTE*: This variable *must* be set in the package Makefile *before*
#         the inclusion of bsd.prefs.mk.
#
# Possible: any of: overwrite, pkgviews
# Default: overwrite

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

PURE_FTPD_USE_MYSQL?=	NO
# Compile in MySQL support.
# Possible: YES, NO
# Default: NO

PURE_FTPD_USE_PGSQL?=	NO
# Compile in PostgreSQL support.
# Possible: YES, NO
# Default: NO

PURE_FTPD_USE_TLS?=	NO
# Compile in SSL/TLS support.
# Possible: YES, NO
# Default: NO

PURE_FTPD_USE_VIRTUAL_CHROOT?=	NO
# Compile in virtual chroot support (enables the ability
# to follow symlinks outside a chroot jail).
# Possible: YES, NO
# Default: NO

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

SILC_CLIENT_WITH_PERL?=	YES
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

USE_ESOUND?= YES
# Whether to compile support for the Enlightened Sound Daemon or not in the
# following packages: libmikmod.
# Possible: YES, or NO.
# Default: YES

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

USE_LIBCRACK?= YES
# Used in PAM and shadow (for Linux) to enable libcrack support.
# Possible: YES, NO
# Default: YES

USE_MMX?=	NO
# Used in eterm, imlib2, libast, and snes9x to specify if the i386 MMX
# extensions should be used.
# Possible: YES, NO
# Default: NO

USE_OPENLDAP?=	NO
# Enable openldap support.  Used in gnupg, dovecot.
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

#USE_SASL2=YES
# Used to specify optional support for SASL authentication version 2.*
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

#USE_TETEX2=
# Used to specify the use of teTeX2 instead of
# teTeX (version 1) for packages which need to
# make a decision.
# Possible: defined, not defined
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

W3M_USE_LYNX_KEY?=		NO
# Enable lynx like keybinding for w3m.
# Possible: YES, NO
# Default: NO

W3M_USE_M17N?=			YES
# For multilingual support for w3m.
# Possible: YES, NO
# Default: YES

W3M_USE_UNICODE?=		NO
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

WINDOWMAKER_THEMES?= freebsdtheme-0.52 netbsddrinkingteam-0.60.0 netbsd_-0.52
# Used in the wmthemes package to specify the themes which will be
# installed.
# Possible: see http://wm.themes.org/
# Default: freebsdtheme-0.52 netbsddrinkingteam-0.60.0 netbsd_-0.52

#X10_PORT=
# The serial device for misc/bottlerocket to use to communicate
# to the X10 adaptor.
# Possible:  /dev/your_favorite_serial_device
# Default: defaults to ${DEFAULT_SERIAL_DEVICE}

WXGTK_USE_GTK1?= NO
# Used in the wxGTK package to request support for GTK+ v1.x instead of v2.x.
# Possible: YES, NO
# Default: NO

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
#	Refer to http://www.NetBSD.org/mirrors/ or /usr/doc/MIRRORS
#	for information on determining the location of NetBSD mirror sites.
#

# Australia.
#
#MASTER_SITE_GNOME=	http://public.planetmirror.com.au/pub/GNOME/
#MASTER_SITE_GNU=	http://public.planetmirror.com.au/pub/gnu/
#MASTER_SITE_MOZILLA=	http://public.planetmirror.com.au/pub/mozilla/releases/
#MASTER_SITE_PERL_CPAN=	http://public.planetmirror.com.au/pub/perl/CPAN/modules/by-module/
#MASTER_SITE_SUNSITE=	http://public.planetmirror.com.au/pub/sunsite/
#MASTER_SITE_SUSE=	http://public.planetmirror.com.au/pub/suse/${MACHINE_ARCH}/${SUSE_VERSION}/suse/ 
#MASTER_SITE_TEX_CTAN=	http://public.planetmirror.com.au/pub/tex-archive/
#MASTER_SITE_SOURCEFORGE=http://flow.dl.sourceforge.net/sourceforge/ \
#			http://public.planetmirror.com.au/pub/sourceforge/
#MASTER_SITE_XCONTRIB=	http://public.planetmirror.com.au/pub/X11/contrib/
#MASTER_SITE_XEMACS=	ftp://ftp.au.xemacs.org/pub/xemacs/
#MASTER_SITE_BACKUP=	ftp://ftp.au.NetBSD.org/pub/NetBSD/packages/distfiles/ \
#			ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/
#MASTER_SITE_LOCAL=	ftp://ftp.au.NetBSD.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/ \
#			ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/
#

# Austria
#
#MASTER_SITE_XCONTRIB=	ftp://ftp.at.NetBSD.org/hci/X11/x.org/contrib/
#MASTER_SITE_GNU=	ftp://ftp.at.NetBSD.org/gnu/gnusrc/
#MASTER_SITE_PERL_CPAN=	ftp://ftp.at.NetBSD.org/languages/perl/CPAN/modules/by-module/
#MASTER_SITE_TEX_CTAN=	ftp://ftp.at.NetBSD.org/publishing/tex/CTAN/
#MASTER_SITE_SUNSITE=	ftp://ftp.univie.ac.at/systems/linux/sunsite/
#MASTER_SITE_XEMACS=	ftp://ftp.at.xemacs.org/editors/xemacs/
#MASTER_SITE_BACKUP=	ftp://ftp.at.NetBSD.org/opsys/NetBSD/packages/distfiles/

# Denmark
#
#MASTER_SITE_GNU=	ftp://ftp.sunsite.auc.dk/pub/gnu/
#MASTER_SITE_PERL_CPAN=	ftp://ftp.sunsite.auc.dk/pub/languages/perl/CPAN/modules/by-module/
#MASTER_SITE_TEX_CTAN=	ftp://ftp.sunsite.auc.dk/pub/tex/ctan/
#MASTER_SITE_SUNSITE=	ftp://ftp.suaunsite.auc.dk/mirrors/sunsite.unc.edu/pub/Linux/
#MASTER_SITE_XEMACS=	ftp://ftp.dk.xemacs.org/pub/emacs/xemacs/
#MASTER_SITE_BACKUP=	ftp://ftp.dk.NetBSD.org/pub/NetBSD/packages/distfiles/

# Finland
#
#MASTER_SITE_XCONTRIB=	ftp://ftp.funet.fi/pub/X11/contrib/
#MASTER_SITE_GNU= 	ftp://ftp.funet.fi/pub/gnu/gnu/
#MASTER_SITE_PERL_CPAN=	\
#	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/
#MASTER_SITE_TEX_CTAN=	ftp://ftp.funet.fi/pub/TeX/CTAN/
#MASTER_SITE_SUNSITE=	\
#	ftp://ftp.funet.fi/pub/mirrors/sunsite.unc.edu/pub/Linux/
#MASTER_SITE_XEMACS=	ftp://ftp.fi.xemacs.org/pub/mirrors/ftp.xemacs.org/pub/tux/xemacs/
#MASTER_SITE_BACKUP=	\
#	ftp://ftp.fi.NetBSD.org/pub/NetBSD/packages/distfiles/

# France
#
#MASTER_SITE_SUSE=	\
#	ftp://fr.rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/ \
#	ftp://fr2.rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/

# Greece
#
#MASTER_SITE_SUSE=	\
#	ftp://ftp.duth.gr/pub/suse/${MACHINE_ARCH}/${SUSE_VERSION}/suse/

# Japan
#
#MASTER_SITE_XCONTRIB=	ftp://ftp.ring.gr.jp/pub/X/opengroup/contrib/
#MASTER_SITE_GNOME=	ftp://ftp.ring.gr.jp/pub/X/gnome/
#MASTER_SITE_GNU=	ftp://ftp.ring.gr.jp/pub/GNU/
#MASTER_SITE_MOZILLA=	ftp://ftp.ring.gr.jp/pub/net/www/mozilla/mozilla/releases/
#MASTER_SITE_PERL_CPAN=	ftp://ftp.ring.gr.jp/pub/lang/perl/CPAN/modules/by-module/
#MASTER_SITE_TEX_CTAN=	ftp://ftp.ring.gr.jp/pub/text/CTAN/
#MASTER_SITE_SUSE=	\
#	ftp://ftp.kddlabs.co.jp/Linux/packages/SuSE/suse/${MACHINE_ARCH}/${SUSE_VERSION}/suse/
#MASTER_SITE_SUNSITE=	ftp://sunsite.sut.ac.jp/pub/archives/linux/sunsite-unc/
#MASTER_SITE_XEMACS=	ftp://ftp.jp.xemacs.org/pub/GNU/xemacs/
#MASTER_SITE_BACKUP=	\
#	ftp://ftp.ring.gr.jp/pub/NetBSD/packages/distfiles/ \
#	ftp://ftp.jp.NetBSD.org/pub/NetBSD/packages/distfiles/

# Switzerland
#
#MASTER_SITE_SUSE=	\
#	ftp://sunsite.cnlab-switch.ch/mirror/SuSE/suse/${MACHINE_ARCH}/${SUSE_VERSION}/suse/

# United Kingdom
#
#MASTER_SITE_XCONTRIB=	ftp://sunsite.org.uk/Mirrors/ftp.x.org/contrib/
#MASTER_SITE_GNU=	ftp://sunsite.org.uk/packages/gnu/
#MASTER_SITE_PERL_CPAN=	ftp://sunsite.org.uk/packages/perl/CPAN/modules/by-module/
#MASTER_SITE_TEX_CTAN=	ftp://sunsite.org.uk/packages/tex/uk-tex/
#MASTER_SITE_SUSE=	\
#	ftp://ftp.mirror.ac.uk/sites/ftp.suse.com/pub/suse/${MACHINE_ARCH}/${SUSE_VERSION}/suse/
#MASTER_SITE_SUNSITE=	ftp://sunsite.org.uk/Mirrors/sunsite.unc.edu/pub/Linux/
#MASTER_SITE_XEMACS=	ftp://ftp.uk.xemacs.org/sites/ftp.xemacs.org/pub/xemacs/
#MASTER_SITE_BACKUP=	\
#	ftp://sunsite.org.uk/packages/NetBSD/packages/distfiles/ \
#	ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/

# USA
#
#MASTER_SITE_SUSE=	\
#	ftp://mirror.mcs.anl.gov/pub/ftp.suse.com/${MACHINE_ARCH}/${SUSE_VERSION}/suse/

# France. This will try to fetch distfile from the distfile mirror
# before trying ${MASTER_SITE} or the distfiles at ftp.NetBSD.org
#
#MASTER_SITE_OVERRIDE=	\
#	ftp://ftp2.fr.NetBSD.org/pub/NetBSD/packages/distfiles/
#MASTER_SITE_BACKUP=	\
#	ftp://ftp2.fr.NetBSD.org/pub/NetBSD/packages/distfiles/
#MASTER_SITE_LOCAL=	\
#	ftp://ftp.fr.NetBSD.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

.if exists(${.CURDIR}/../../mk/bsd.pkg.obsolete.mk)
.include "${.CURDIR}/../../mk/bsd.pkg.obsolete.mk"
.elif exists(${.CURDIR}/../mk/bsd.pkg.obsolete.mk)
.include "${.CURDIR}/../mk/bsd.pkg.obsolete.mk"
.elif exists(${.CURDIR}/mk/bsd.pkg.obsolete.mk)
.include "${.CURDIR}/mk/bsd.pkg.obsolete.mk"
.endif
