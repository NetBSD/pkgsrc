# $NetBSD: SunOS.mk,v 1.40 2011/09/10 16:30:02 abs Exp $
#
# Variable definitions for the SunOS/Solaris operating system.

ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	/usr/ccs/bin/make	# program which gets invoked by imake
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
MOTIF_TYPE_DEFAULT?=	dt		# default 2.0 compatible libs type
NOLOGIN?=		/usr/bin/false
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		root
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `${SETENV} LC_MESSAGES=C ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `${SETENV} LC_MESSAGES=C ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -v `${SETENV} LC_MESSAGES=C ulimit -H -v`
USERADD?=		/usr/sbin/useradd

X11_TYPE?=		native

# imake installs manpages in weird places
.if !defined(X11_TYPE) || defined(X11_TYPE) && !empty(X11_TYPE:Mnative)
# openwindows
IMAKE_MAN_SOURCE_PATH=	share/man/man
IMAKE_MAN_SUFFIX=	1
IMAKE_LIBMAN_SUFFIX=	3
.else
# xfree86, xorg
IMAKE_MAN_SOURCE_PATH=	man/man
IMAKE_MAN_SUFFIX=	1x
IMAKE_LIBMAN_SUFFIX=	3x
.endif
IMAKE_FILEMAN_SUFFIX=	4
IMAKE_GAMEMAN_SUFFIX=	6
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}4
IMAKE_GAMEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}6
IMAKE_MANNEWSUFFIX=	${IMAKE_MAN_SUFFIX}
IMAKE_MANINSTALL?=	maninstall

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

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
# FIXME: Adjust to work on this system and enable the lines below.
#_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax
