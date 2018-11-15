# $NetBSD: Minix.mk,v 1.9 2018/11/15 01:05:09 sevan Exp $
#
# Variable definitions for the Minix operating system.

ECHO_N?=	${ECHO} -n
X11_TYPE?=	native
IMAKE_MAKE?=	${MAKE}	# program which gets invoked by imake
IMAKEOPTS+=	-DBuildHtmlManPages=NO
PKGLOCALEDIR?=	share
PS?=		/usr/bin/ps
SU?=		/usr/bin/su
TYPE?=		type			# Shell builtin

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
GROUPADD?=		/usr/sbin/groupadd
NOLOGIN?=		/usr/bin/false
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?= 		wheel
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
USERADD?=		/usr/sbin/useradd
ULIMIT_CMD_datasize?=	: 
ULIMIT_CMD_stacksize?=	: 

_OPSYS_SYSTEM_RPATH?=	/usr/lib
_OPSYS_LIB_DIRS?=	/usr/lib
_OPSYS_INCLUDE_DIRS?=	/usr/include

_OPSYS_HAS_INET6=	yes	# IPv6 is standard
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	no	# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF	# ELF shared libraries on Minix
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?= 	-b -V simple --suffix	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

_OPSYS_CAN_CHECK_SHLIBS=	yes
