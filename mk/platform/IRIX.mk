# $NetBSD: IRIX.mk,v 1.27 2006/09/10 13:44:58 schwarz Exp $
#
# Variable definitions for the IRIX operating system.

ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	${MAKE}		# program which gets invoked by imake
IMAKEOPTS+=	-DMakeCmd=${PREFIX}/bin/bmake -DProjectRoot=${X11BASE}
IMAKEOPTS+=	-DManUsr=${PREFIX}
.if empty(OS_VERSION:M6*)
IMAKEOPTS+=	-DShLibDir=${X11BASE}/lib
IMAKEOPTS+=	-DOptimizerLevel="${CFLAGS}"
IMAKEOPTS+=	-DManPath=${PREFIX}/man
.endif
PKGLOCALEDIR?=	share
PS?=		/sbin/ps
RSH?=		/usr/bsd/rsh
SU?=		/sbin/su
TYPE?=		/sbin/type

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
MOTIF_TYPE_DEFAULT?=	dt		# default 2.0 compatible libs type
NOLOGIN?=		${FALSE}
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		sys
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -v `ulimit -H -v`

# imake installs manpages in weird places
.if !empty(OS_VERSION:M6*)
IMAKE_MAN_SOURCE_PATH?=	catman/u_man/cat
IMAKE_MAN_SUFFIX?=	1
IMAKE_LIBMAN_SUFFIX?=	3
IMAKE_FILEMAN_SUFFIX?=	5
IMAKE_GAMEMAN_SUFFIX?=	6
IMAKE_MAN_DIR?=		${IMAKE_MAN_SOURCE_PATH}1/X11
IMAKE_LIBMAN_DIR?=	${IMAKE_MAN_SOURCE_PATH}3/X11
IMAKE_FILEMAN_DIR?=	${IMAKE_MAN_SOURCE_PATH}5/X11
IMAKE_GAMEMAN_DIR?=	${IMAKE_MAN_SOURCE_PATH}6/X11
IMAKE_MANNEWSUFFIX?=	z
IMAKE_MANINSTALL?=	maninstall
.else
IMAKE_MAN_SOURCE_PATH?=	man/man
IMAKE_MAN_SUFFIX?=	1.gz
IMAKE_LIBMAN_SUFFIX?=	3.gz
IMAKE_FILEMAN_SUFFIX?=	5.gz
IMAKE_GAMEMAN_SUFFIX?=	6.gz
IMAKE_MAN_DIR?=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR?=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_FILEMAN_DIR?=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_GAMEMAN_DIR?=	${IMAKE_MAN_SOURCE_PATH}6
IMAKE_MANNEWSUFFIX?=	${IMAKE_MAN_SUFFIX}
. if defined(USE_IMAKE) && !empty(USE_IMAKE:M[Yy][Ee][Ss])
MAKE_ENV+=		GZIP_CMD="${GZIP_CMD}"
USE_TOOLS+=		gzip
MANCOMPRESSED=		yes
MANZ=			yes
. endif
.endif

.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes		# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no		# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no		# Java is not standard
_OPSYS_HAS_MANZ=	no		# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no		# libossaudio is available
_OPSYS_NEEDS_XPKGWEDGE=	yes		# xpkgwedge is required for X11
_OPSYS_PERL_REQD=			# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no		# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF		# shared lib type
.if defined(_OPSYS_GPATCH_REQD) && ${_OPSYS_GPATCH_REQD} == "YES"
_PATCH_CAN_BACKUP=	yes		# patch(1) can make backups
_PATCH_BACKUP_ARG?=	-b -V simple -z # switch to patch(1) for backup suffix
.else
_PATCH_CAN_BACKUP=	no		# native patch(1) can make backups
.endif
_USE_RPATH=		yes		# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# XXX:
# These flags are for the IRIX linker.  If GNU ld is used, these would need
# to be set to --{no-}whole-archive.  So, ugh, let's say we only do
# IRIX tools for the time being.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,-all
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,-none

# IRIX has /usr/include/iconv.h, but it's not GNU iconv, so mark it
# incompatible.
_INCOMPAT_ICONV=	IRIX-*-*

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-S -f}	# install(1) option to strip

LOCALBASE?=		${DESTDIR}/usr/pkg
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin

CONFIGURE_ENV+=		ABI=${ABI:Q}
MAKE_ENV+=		ABI=${ABI:Q}

LIBABISUFFIX?=		${ABI}

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
_OPSYS_MAX_CMDLEN_CMD=	/usr/sbin/sysconf ARG_MAX

# If games are to be installed setgid, then SETGIDGAME is set to 'yes'
# (it defaults to 'no' as per defaults/mk.conf).
# Set the group and mode to meaningful values in that case (defaults to
# BINOWN, BINGRP and BINMODE as per defaults/mk.conf).
# FIXME: Adjust to work on this system and enable the lines below.
#.if !(empty(SETGIDGAME:M[yY][eE][sS]))
#GAMEOWN=		games
#GAMEGRP=		games
#GAMEMODE=		2555
#GAMEDIRMODE=		0775
#.endif
