# $NetBSD: Haiku.mk,v 1.9 2013/11/23 07:50:51 obache Exp $
#
# Variable definitions for the Haiku operating system.

ECHO_N?=	${ECHO} -n
PKGLOCALEDIR?=	share
PS?=		/bin/ps
# XXX: default from defaults/mk.conf.  Verify/correct for this platform
# and remove this comment.
SU?=		/bin/su
TYPE?=		type			# Shell builtin
 
# Use symlink for wrapper in mk/wrapper/bsd.wrapper.mk,
# due to lack of hard link support.
WRAPPER_USE_SYMLINK=	# defined

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/tty
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
#GROUPADD?=		/bin/groupadd
MOTIF_TYPE_DEFAULT?=	motif	# default 2.0 compatible libs type
NOLOGIN?=		/bin/false
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		root
ROOT_USER?=		user
SERIAL_DEVICES?=	/dev/tty
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`
USERADD?=		/bin/useradd

_OPSYS_SYSTEM_RPATH?=	/boot/common/lib:/boot/system/lib
_OPSYS_LIB_DIRS?=	/boot/common/lib /boot/system/lib
_OPSYS_INCLUDE_DIRS?=	/boot/common/include \
			/boot/develop/headers/posix \
			/boot/develop/headers/3rdparty

_OPSYS_HAS_INET6=	yes	# IPv6 is standard
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	no	# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?= 	-b -V simple -z	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
# FIXME: Adjust to work on this system and enable the lines below.
#_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax
