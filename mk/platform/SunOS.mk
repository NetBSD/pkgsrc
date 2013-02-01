# $NetBSD: SunOS.mk,v 1.48 2013/02/01 12:36:06 hans Exp $
#
# Variable definitions for the SunOS/Solaris operating system.

ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	${MAKE}	# program which gets invoked by imake
PKGLOCALEDIR?=	lib
PS?=		/bin/ps
# XXX: default from defaults/mk.conf.  Verify/correct for this platform
# and remove this comment.
SU?=		/usr/bin/su
TYPE?=		/usr/bin/type

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
GROUPADD?=		/usr/sbin/groupadd
NOLOGIN?=		/usr/bin/false
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		root
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `${SETENV} LC_MESSAGES=C ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `${SETENV} LC_MESSAGES=C ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -v `${SETENV} LC_MESSAGES=C ulimit -H -v`
USERADD?=		/usr/sbin/useradd

.if exists(/usr/openwin/include/X11/X.h)
X11_TYPE?=		native
.else
X11_TYPE?=		modular
.endif
.if ${X11_TYPE} == native
MOTIF_TYPE_DEFAULT?=	dt		# default 2.0 compatible libs type
.else
MOTIF_TYPE_DEFAULT?=	motif
.endif

# Builtin defaults which make sense for this platform.
PREFER.solaris-pam?=	native
PREFER.openssl?=	pkgsrc

_OPSYS_EMULDIR.solaris=		# empty
_OPSYS_EMULDIR.solaris32=	# empty
_OPSYS_EMULDIR.sunos=		# empty

.if exists(/usr/include/netinet/ip6.h)
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
_OPSYS_MISSING_FEATURES=asprintf
_PATCH_CAN_BACKUP=	yes		# native patch(1) can make backups
_PATCH_BACKUP_ARG?= 	-b -V simple -z	# switch to patch(1) for backup suffix
_USE_RPATH=		yes		# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is the standard Solaris linker, /usr/ccs/bin/ld. The use of GNU
# ld is not currently supported.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-z allextract
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-z defaultextract

# Solaris has /usr/include/iconv.h, but it's not GNU iconv, so mark it
# incompatible.
_INCOMPAT_ICONV=	SunOS-*-*

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

PKG_TOOLS_BIN?=		${LOCALBASE}/sbin

.if (${MACHINE_ARCH} == "x86_64")
LIBABISUFFIX=		/amd64
.endif

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
# FIXME: Adjust to work on this system and enable the lines below.
#_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax
