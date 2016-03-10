# $NetBSD: IRIX.mk,v 1.43 2016/03/10 16:58:19 jperkin Exp $
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

USERADD?=		${LOCALBASE}/sbin/useradd
GROUPADD?=		${LOCALBASE}/sbin/groupadd
_PKG_USER_HOME?=	/dev/null # to match other system accounts
_USER_DEPENDS=		user-irix>=20130712:../../sysutils/user_irix

_OPSYS_EMULDIR.irix=	# empty

_OPSYS_SYSTEM_RPATH?=	/usr/lib
_OPSYS_LIB_DIRS?=	/usr/lib
_OPSYS_INCLUDE_DIRS?=	/usr/include

.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes		# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no		# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no		# Java is not standard
_OPSYS_HAS_MANZ=	no		# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no		# libossaudio is available
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

# IRIX has /usr/include/iconv.h, but it's not GNU iconv, so mark it
# incompatible.
_INCOMPAT_ICONV=	IRIX-*-*

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-S -f}	# install(1) option to strip

PKG_TOOLS_BIN?=		${LOCALBASE}/sbin

CONFIGURE_ENV+=		ABI=${ABI:Q}
MAKE_ENV+=		ABI=${ABI:Q}

LIBABISUFFIX?=		${ABI}

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
_OPSYS_MAX_CMDLEN_CMD=	/usr/sbin/sysconf ARG_MAX
