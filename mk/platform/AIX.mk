# $NetBSD: AIX.mk,v 1.42 2016/03/10 16:58:19 jperkin Exp $
#
# Variable definitions for the AIX operating system.

CPP?=		${LOCALBASE}/bin/cpp
ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	${MAKE}		# program which gets invoked by imake
PKGLOCALEDIR?=	share
PS?=		/bin/ps
# XXX: default from defaults/mk.conf.  Verify/correct for this platform
# and remove this comment.
# AIX strip fails too easily.  Use a wrapper script instead
.if exists(${LOCALBASE}/bin/strip)
STRIP?=     ${LOCALBASE}/bin/strip
.endif
SU?=		/usr/bin/su
TYPE?=		type				# Shell builtin

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		0022
EXPORT_SYMBOLS_LDFLAGS?=	# empty
MOTIF_TYPE_DEFAULT?=	motif	# default 2.0 compatible libs type
NOLOGIN?=		/sbin/nologin
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_USER?=		root
ROOT_GROUP?=		system
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`

_OPSYS_SYSTEM_RPATH?=		/usr/lib
_OPSYS_LIB_DIRS?=		/usr/lib
_OPSYS_INCLUDE_DIRS?=		/usr/include

.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	aixlib	# type of shared lib
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-b -V simple -z 	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

DEFAULT_SERIAL_DEVICE?=	/dev/tty0
SERIAL_DEVICES?=	/dev/tty0 \
			/dev/tty

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
# FIXME: Adjust to work on this system and enable the lines below.
#_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax

# On AIX, there are a handful of utilies (i.e., ar(1), ld(1), strip(1), etc)
# that care about the type of object files they should examine via the various'
# flags.  Alternatively, it is easier to export OBJECT_MODE with the
# appropriate $ABI versus piping through flags for all related utilities.
.if defined(ABI)
ALL_ENV+=	OBJECT_MODE=${ABI}
.endif
