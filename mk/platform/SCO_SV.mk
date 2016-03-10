# $NetBSD: SCO_SV.mk,v 1.2 2016/03/10 16:58:19 jperkin Exp $
#
# Variable definitions for the OpenServer 5.0.7/3.2 and 6.0.0/5.

ECHO_N?=	${ECHO} -n
PKGLOCALEDIR?=	lib
PS?=		/bin/ps
SU?=		/bin/su
TYPE?=		type			# Shell builtin

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
GROUPADD?=		/etc/groupadd
MOTIF_TYPE_DEFAULT?=	dt		# default 2.0 compatible libs type
NOLOGIN?=		${FALSE}
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		root
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
TOUCH_FLAGS?=		# touch doesn't understand -f
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -v `ulimit -H -v`
USERADD?=		/etc/useradd

_OPSYS_SYSTEM_RPATH?=	/lib:/usr/lib:/usr/gnu/lib
_OPSYS_LIB_DIRS?=	/lib/lib /usr/lib /usr/gnu/lib

_OPSYS_HAS_INET6=	no		# IPv6 is not standard
_OPSYS_HAS_JAVA=	yes		# Java is not standard
_OPSYS_HAS_MANZ=	no		# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no		# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no		# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF		# shared lib type
_PATCH_CAN_BACKUP=	yes		# native patch(1) can make backups
_PATCH_BACKUP_ARG?= 	-b -V simple -z	# switch to patch(1) for backup suffix
#
# The native linker for OpenServer doesn't really support an option to pass
# rpath directives, but pretend it does anyway since the wrapper scripts
# will correctly convert it into the proper LD_RUN_PATH variable.
#
_USE_RPATH=		yes		# add rpath to LDFLAGS

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U}	# install(1) option to strip

PKG_TOOLS_BIN?=		${LOCALBASE}/sbin

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

# Use native curses to avoid circular dependency.
_OPSYS_PREFER.curses?=		native

.if ${OS_VARIANT} == "SCOOSR5"
# SCO OpenServer 5.0.7/3.2's /bin/rm cannot accepr "rm -f" (without arg).
CONFIGURE_ENV+=		ACCEPT_INFERIOR_RM_PROGRAM=yes
# pkgsrc does not support SCO OpenServer 5.0.7/3.2's native CC (yet).
BUILDLINK_TRANSFORM+=	rm:-belf
# SCO OpenServer 5.0.7/3.2's pthread is GNU pth and it requires -lsocket.
BUILDLINK_TRANSFORM+=   l:pthread:pthread:socket
# SCO OpenServer 5.0.7/3.2's pthread library is GNU pth (builtin).
PTHREAD_TYPE=	pth
# SCO OpenServer 5.0.7/3.2 has no IPv6 support.
_OPSYS_MISSING_FEATURES=	inet6
PKG_DEFAULT_OPTIONS=		-inet6
.endif
