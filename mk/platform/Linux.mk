# $NetBSD: Linux.mk,v 1.36 2010/02/13 08:29:12 obache Exp $
#
# Variable definitions for the Linux operating system.

ECHO_N?=	${ECHO} -n
.if !defined(X11_TYPE) || ${X11_TYPE} == "native"
IMAKE_MAKE?=	${GMAKE}	# program which gets invoked by imake
.endif
IMAKEOPTS+=	-DBuildHtmlManPages=NO
PKGLOCALEDIR?=	share
PS?=		/bin/ps
# XXX: default from defaults/mk.conf.  Verify/correct for this platform
# and remove this comment.
SU?=		/bin/su
TYPE?=		type			# Shell builtin

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
GROUPADD?=		/usr/sbin/groupadd
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
.if exists(/usr/bin/false)
NOLOGIN?=		/usr/bin/false
.else
NOLOGIN?=		/bin/false
.endif
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
.if exists(/etc/ssdlinux_version)
ROOT_GROUP?=		wheel
.else
ROOT_GROUP?=		root
.endif
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`
USERADD?=		/usr/sbin/useradd

# imake installs manpages in weird places
# these values from /usr/X11R6/lib/X11/config/linux.cf
IMAKE_MAN_SOURCE_PATH=	man/man
IMAKE_MAN_SUFFIX=	1x
IMAKE_LIBMAN_SUFFIX=	3x
IMAKE_KERNMAN_SUFFIX=	4
IMAKE_FILEMAN_SUFFIX=	5x
IMAKE_GAMEMAN_SUFFIX=	6
IMAKE_MISCMAN_SUFFIX=	7
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_KERNMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}4
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_GAMEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}6
IMAKE_MISCMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}7
IMAKE_MANNEWSUFFIX=	${IMAKE_MAN_SUFFIX}
IMAKE_MANINSTALL?=	maninstall catinstall
IMAKE_TOOLS=		gmake	# extra tools required when we use imake

_OPSYS_EMULDIR.linux=	# empty
_OPSYS_EMULDIR.linux32=	# empty

.if exists(/usr/include/netinet6) || exists(/usr/include/linux/in6.h)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	no	# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?= 	-b -V simple -z	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
# FIXME: Adjust to work on this system and enable the lines below.
#_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax

# If games are to be installed setgid, then SETGIDGAME is set to 'yes'
# (it defaults to 'no' as per defaults/mk.conf).
# Set the group and mode to meaningful values in that case (defaults to
# BINOWN, BINGRP and BINMODE as per defaults/mk.conf).
# FIXME: Adjust to work on this system and enable the lines below.
#.if !(empty(SETGIDGAME:M[yY][eE][sS]))
#GAMES_USER=		games
#GAMES_GROUP=		games
#GAMEOWN=		${GAMES_USER}
#GAMEGRP=		${GAMES_GROUP}
#GAMEMODE=		2555
#GAMEDIRMODE=		0775
#.endif

.if (${MACHINE_ARCH} == "x86_64")
ABI?=	64
LIBABISUFFIX?=          64
.endif
