# $NetBSD: Interix.mk,v 1.33 2005/05/03 18:30:12 jlam Exp $
#
# Variable definitions for the Interix operating system.

# SHLIB BASE ADDRESSES:
#
# [tv] For reference, here's a list of shared library base address ranges used
# throughout pkgsrc to cope with the fact that Interix has no proper PIC
# support in the compiler.  This list will be kept updated for any new packages
# also needing special handling.
#
# Fortunately, libtool covers most of this, and uses a randomized base address
# selection as described below.  This randomized base address concept is used
# again in a couple other places.
#
# * = currently uses fixed default of 0x10000000 and needs something better
#     (this base address restricts how far sbrk() can go in memory, and of
#     course, collides with everything else, requiring runtime text relocs)
#
# pkg		start		end		slotsize	#slots
#
# <bsd.lib.mk>	0x50000000	0x6fffffff	0x00040000	2048
# libtool-base	0x50000000	0x6fffffff	0x00040000	2048
# netpbm	0x6b000000	0x6cffffff	0x00100000	32
# openssl	0x5e000000	0x5fffffff	0x00100000	32
# perl58	*
# python22	*
# python23	*
# python24	*
# ruby16	0x50000000	0x6fffffff	0x00040000	2048
#   (main lib)	0x48000000
# ruby18	0x50000000	0x6fffffff	0x00040000	2048
#   (main lib)	0x48000000
# zsh		*

BULK_PREREQ+=	converters/libiconv devel/gettext-lib pkgtools/pkg_install-info
BULK_PREREQ+=	lang/gawk sysutils/coreutils

# "catinstall" not yet supported as there's no shipped [gn]roff
MANINSTALL=	maninstall
MAKE_FLAGS+=	MKCATPAGES=no NOLINT=1

ECHO_N?=	/bin/printf %s			# does not support "echo -n"
IMAKEOPTS+=	-DBuildHtmlManPages=NO
PKGLOCALEDIR?=	share
PS?=		/bin/ps
RSH?=		/usr/bin/rsh
SU?=		/bin/su
TYPE?=		type				# Shell builtin

.if empty(_USE_NEW_TOOLS:M[yY][eE][sS])

# Use some pkgsrc versions as "better" replacements, if installed
.if exists(${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}awk)
AWK?=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}awk
.endif
.if exists(${LOCALBASE}/bin/gtar)
GTAR?=		${LOCALBASE}/bin/gtar
.endif

AWK?=		/usr/contrib/bin/gawk
BASENAME?=	/bin/basename
CAT?=		/bin/cat
CHMOD?=		/bin/chmod
CHOWN?=		/bin/chown
CHGRP?=		/bin/chgrp
CMP?=		/bin/cmp
CP?=		/bin/cp
CUT?=		/bin/cut
DATE?=		/bin/date
DIRNAME?=	/bin/dirname
ECHO?=		echo				# Shell builtin
EGREP?=		/bin/egrep
EXPR?=		/bin/expr
FALSE?=		false				# Shell builtin
FGREP?=		/bin/fgrep
FILE_CMD?=	/bin/file
FIND?=		/bin/find
GMAKE?=		${LOCALBASE}/bin/gmake
GREP?=		/bin/grep
GTAR?=		${LOCALBASE}/bin/tar
GUNZIP_CMD?=	/usr/contrib/bin/gunzip -f
GZCAT?=		/usr/contrib/bin/gunzip -c
GZIP_CMD?=	/usr/contrib/bin/gzip -nf ${GZIP}
HEAD?=		/bin/head
HOSTNAME_CMD?=	/bin/hostname
ID?=		/bin/id
IMAKE?=		${X11BASE}/bin/imake ${IMAKEOPTS}
LDCONFIG?=	/bin/true
LN?=		/bin/ln
LS?=		/bin/ls
M4?=		/bin/m4
MAIL_CMD?=	/bin/mail
MKDIR?=		/bin/mkdir -p
MTREE?=		${LOCALBASE}/sbin/mtree
MV?=		/bin/mv
NICE?=		/bin/nice
PATCH?=		${LOCALBASE}/bin/gpatch
PAX?=		${LOCALBASE}/bin/pax
PERL5?=		${LOCALBASE}/bin/perl
PWD_CMD?=	/bin/pwd	# needs to print physical path
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
SED?=		${LOCALBASE}/bin/nbsed
SETENV?=	/bin/env
SH?=		/bin/sh
SHLOCK=		${LOCALBASE}/bin/shlock
SORT?=		/bin/sort
TAIL?=		/bin/tail
TAR?=		${LOCALBASE}/bin/tar
TEE?=		/bin/tee
TEST?=		/bin/test	# shell builtin has bugs with symlinks
TOUCH?=		/bin/touch
TR?=		/bin/tr
TRUE?=		true				# Shell builtin
TSORT?=		/bin/tsort
WC?=		/bin/wc
XARGS?=		/bin/xargs
.endif

USERADD?=		${LOCALBASE}/sbin/useradd
GROUPADD?=		${LOCALBASE}/sbin/groupadd
_PKG_USER_HOME?=	# empty by default
_USER_DEPENDS=		user>=20040426:../../sysutils/user_interix

CPP_PRECOMP_FLAGS?=	# unset
CONFIG_RPATH_OVERRIDE?=	config.rpath */config.rpath */*/config.rpath
DEF_UMASK?=		002
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table

MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
NOLOGIN?=		/bin/false
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
PKGDIRMODE?=		775
# ROOT_USER might be numeric in the special case of Administrator; canonify it:
ROOT_CMD?=		${SU} - "$$(id -un ${ROOT_USER})" -c
ROOT_USER?=		${BINOWN}
ROOT_GROUP?=		131616 # +Administrators or native language equivalent
TOUCH_FLAGS?=
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -v `ulimit -H -v`

# imake installs manpages in weird places
IMAKE_MAN_SOURCE_PATH=	man/man
IMAKE_MAN_SUFFIX=	n
IMAKE_LIBMAN_SUFFIX=	3
IMAKE_KERNMAN_SUFFIX=	4
IMAKE_FILEMAN_SUFFIX=	5
IMAKE_MISCMAN_SUFFIX=	7
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}n
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_KERNMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}4
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_MISCMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}7
IMAKE_MANNEWSUFFIX=	${IMAKE_MAN_SUFFIX}

_DO_SHLIB_CHECKS=	yes	# fixup PLIST for shared libs/run ldconfig
_IMAKE_MAKE=		${MAKE}	# program which gets invoked by imake
.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=	5.8.3nb1 # base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF	# shared lib type - not exactly true, but near enough
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-b -V simple -z	# switch to patch(1) for backup suffix
_PREFORMATTED_MAN_DIR=	cat	# directory where catman pages are
_USE_GNU_GETTEXT=	yes	# gettext not in base system
_USE_RPATH=		yes	# add rpath to LDFLAGS

# Ensure that USE_X11BASE programs get an xpkgwedge new enough to work.
_OPSYS_NEEDS_XPKGWEDGE=	yes	# xpkgwedge is required for X11
_XPKGWEDGE_DEPENDS=	xpkgwedge>=1.10:../../pkgtools/xpkgwedge
BUILD_DEPENDS+=		${USE_X11BASE:D${_XPKGWEDGE_DEPENDS}}

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

DEFAULT_SERIAL_DEVICE?=	/dev/tty00
SERIAL_DEVICES?=	/dev/tty00 /dev/tty01 /dev/tty02 /dev/tty03

# poll(2) is broken; try to work around it by making autoconf believe
# it's missing.  (Packages without autoconf will need explicit fixing.)
CONFIGURE_ENV+=		${GNU_CONFIGURE:Dac_cv_header_poll_h=no ac_cv_func_poll=no}

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
_OPSYS_MAX_CMDLEN_CMD=	${ECHO} 262144

# If games are to be installed setgid, then SETGIDGAME is set to 'yes'
# (it defaults to 'no' as per bsd.pkg.defaults.mk).
# Set the group and mode to meaningful values in that case (defaults to
# BINOWN, BINGRP and BINMODE as per bsd.pkg.defaults.mk).
# FIXME: Adjust to work on this system and enable the lines below.
#.if !(empty(SETGIDGAME:M[yY][eE][sS]))
#GAMEOWN=		games
#GAMEGRP=		games
#GAMEMODE=		2555
#.endif
