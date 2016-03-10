# $NetBSD: HPUX.mk,v 1.26 2016/03/10 16:58:19 jperkin Exp $
#
# Variable definitions for the HP-UX operating system.

ECHO_N?=	/usr/bin/printf		# echo doesn't understand -n
IMAKE_MAKE?=	${MAKE}			# program which gets invoked by imake
PKGLOCALEDIR=	share
PS?=		/bin/ps
SU?=		/usr/bin/su
TYPE?=		type			# Shell builtin

USERADD?=	/usr/sbin/useradd
GROUPADD?=	/usr/sbin/groupadd

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		0022
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table
MOTIF_TYPE_DEFAULT?=	motif	# default 2.0 compatible libs type
NOLOGIN?=		/usr/bin/false
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_USER?=		root
ROOT_GROUP?=		sys
TOUCH_FLAGS?=				# touch doesn't understand -f
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`

# Fix broken system headers by using pkgtools/compat_headers
FIX_SYSTEM_HEADERS?=	yes

_OPSYS_EMULDIR.hpux=	# empty

_OPSYS_SYSTEM_RPATH?=	/usr/lib
_OPSYS_LIB_DIRS?=	/usr/lib
_OPSYS_INCLUDE_DIRS?=	/usr/include

.if exists(/usr/include/netinet/ip6.h)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	yes	# Java is standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	${OBJECT_FMT}	# type of shared lib
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-b -V simple -z	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

DEFAULT_SERIAL_DEVICE?=	/dev/tty1p0
SERIAL_DEVICES?=	/dev/tty0p0 \
			/dev/tty1p0

_INCOMPAT_ICONV=   HPUX-*-*

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

# sysutils/fam is not usable on HP-UX.
FAM_DEFAULT?=		gamin

# mit-krb5 is builtin, and heimdal doesn't build.
KRB5_DEFAULT?=		mit-krb5

# Builtin openssl and zlib have issues. Prefer pkgsrc's until we know which
# versions work.
_OPSYS_PREFER.openssl?=	pkgsrc
_OPSYS_PREFER.zlib?=	pkgsrc

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U}	# install(1) option to strip
