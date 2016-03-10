# Variable definitions for the QNX operating system.

ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	${MAKE}		# program which gets invoked by imake
PKGLOCALEDIR?=	share
PS?=		/bin/ps
SU?=		/bin/su
TYPE?=		type				# Shell builtin
TOUCH_FLAGS?=

USERADD?=	/usr/sbin/passwd

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		0002
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
NOLOGIN?=		/bin/false
.if exists(${LOCALBASE}/sbin/pkg_info)
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
.else
PKG_TOOLS_BIN?=		/usr/sbin
.endif
ROOT_CMD?=		${SU} - root -c
ROOT_USER?=		root
ROOT_GROUP?=		root
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`

# QNX does not provide an X11, so default to modular X.org
X11_TYPE?=		modular

# imake installs manpages in weird places
# these values from /usr/X11R6/lib/X11/config/NetBSD.cf
IMAKE_MAN_SOURCE_PATH=	man/cat
IMAKE_MANNEWSUFFIX=	0
IMAKE_MAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_LIBMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_KERNMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_FILEMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_GAMEMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_MISCMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_KERNMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}4
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_GAMEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}6
IMAKE_MISCMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}7
IMAKE_MANINSTALL?=	maninstall catinstall

_OPSYS_SYSTEM_RPATH?=	/lib:/usr/lib	# STANDARD_LIBRARY_PATH
_OPSYS_LIB_DIRS?=	/lib /usr/lib
_OPSYS_INCLUDE_DIRS?=	/usr/include

.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	no	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is not available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	yes	# -lpthread not needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-V simple -b -z 	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

DEFAULT_SERIAL_DEVICE?=	/dev/ser1
SERIAL_DEVICES?=	/dev/ser1 \
			/dev/ser2
_OPSYS_CAN_CHECK_SHLIBS=	yes # use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
_OPSYS_MAX_CMDLEN_CMD=	/usr/bin/getconf ARG_MAX

# If games are to be installed setgid, then SETGIDGAME is set to 'yes'
# (it defaults to 'no' as per defaults/mk.conf).
# Set the group and mode to meaningful values in that case (defaults to
# BINOWN, BINGRP and BINMODE as per defaults/mk.conf).
.if !(empty(SETGIDGAME:M[yY][eE][sS]))
GAMES_USER=		games
GAMES_GROUP=		games
GAMEOWN=		${GAMES_USER}
GAMEGRP=		${GAMES_GROUP}
GAMEMODE=		2555
GAMEDIRMODE=		0775
.endif

_OPSYS_PREFER.zlib?=	pkgsrc
_OPSYS_PREFER.bzip2?=	pkgsrc
_OPSYS_PREFER.curses?=	pkgsrc
_OPSYS_PREFER.termcap?=	pkgsrc
