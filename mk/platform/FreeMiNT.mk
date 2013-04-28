# $NetBSD: FreeMiNT.mk,v 1.3 2013/04/28 12:53:56 obache Exp $
#
# Variable definitions for the FreeMiNT operating system.

ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	${MAKE}		# program which gets invoked by imake
PKGLOCALEDIR=	share
PS?=		/bin/ps
STRIP?=		/usr/bin/strip
SU?=		/bin/su
TYPE?=		type				# Shell builtin

USERADD?=	/usr/sbin/useradd
GROUPADD?=	/usr/sbin/groupadd

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		0022
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_USER?=		root
ROOT_GROUP?=		root
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`

_OPSYS_EMULDIR.osf1=	# empty

_OPSYS_SYSTEM_RPATH?=		/usr/lib
_OPSYS_LIB_DIRS?=		/usr/lib
_OPSYS_INCLUDE_DIRS?=		/usr/include

_OPSYS_HAS_INET6=	no	# IPv6 is not standard
_OPSYS_HAS_JAVA=	no	# Java is standard
_OPSYS_HAS_MANZ=	no	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_OPSYS_SHLIB_TYPE=	none	# shared lib type
_PATCH_BACKUP_ARG?=	-b -V simple -z	# switch to patch(1) for backup suffix

DEFAULT_SERIAL_DEVICE?=	/dev/modem1
SERIAL_DEVICES?=	/dev/modem1 

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk
