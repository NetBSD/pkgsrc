# $NetBSD: BSDOS.mk,v 1.30 2011/09/17 08:06:40 abs Exp $
#
# Variable definitions for the BSD/OS operating system.

#CPP=		/usr/bin/cpp
# BSD/OS doesn't have c++ command
.if !exists(${CXX})
CXX=		/usr/bin/g++
.endif
ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	${MAKE}		# program which gets invoked by imake
PKGLOCALEDIR?=	share
PS?=		/bin/ps
# XXX: default from defaults/mk.conf.  Verify/correct for this platform
# and remove this comment.
SU?=		/usr/bin/su
# sh doesn't have built-in type
TYPE?=		which

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		0022
.if ${OBJECT_FMT} == "ELF"
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table
.else
EXPORT_SYMBOLS_LDFLAGS?=-Wl,--export-dynamic
.endif
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
NOLOGIN?=		/sbin/nologin
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_USER?=		root
ROOT_GROUP?=	wheel
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`

# imake installs manpages in weird places
# XXX: assume NetBSD defaults until somebody determines correct values
IMAKE_MAN_SOURCE_PATH=	man/cat
IMAKE_MANNEWSUFFIX=	0
IMAKE_MAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_LIBMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_FILEMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_GAMEMAN_SUFFIX=	${IMAKE_MANNEWSUFFIX}
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_GAMEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}6
IMAKE_MANINSTALL?=	maninstall catinstall

.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
# XXX need to check this for Java
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
# XXX need to check this for libossaudio
_OPSYS_HAS_OSSAUDIO=	yes	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF/a.out	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-V simple -b -z	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

DEFAULT_SERIAL_DEVICE?=	/dev/null
SERIAL_DEVICES?=	/dev/null

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

PKG_CREATE_USERGROUP=	NO # until it works

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
# FIXME: Adjust to work on this system and enable the lines below.
#_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax
