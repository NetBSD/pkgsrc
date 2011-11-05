# $NetBSD: Minix.mk,v 1.1 2011/11/05 17:09:15 tcort Exp $
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
GROUPADD?=
NOLOGIN?=		/bin/false
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=	operator
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
USERADD?=		/usr/bin/useradd
ULIMIT_CMD_datasize?=	: 

# imake installs manpages in weird places
# these values from /usr/X11R6/lib/X11/config/linux.cf
IMAKE_MAN_SOURCE_PATH=	man/man
IMAKE_MAN_SUFFIX=	1x
IMAKE_LIBMAN_SUFFIX=	3x
IMAKE_KERNMAN_SUFFIX=	4
IMAKE_FILEMAN_SUFFIX=	5x
IMAKE_GAMEMAN_SUFFIX=	6
IMAKE_MISCMAN_SUFFIX=	7
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_KERNMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}4
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_GAMEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}6
IMAKE_MISCMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}7
IMAKE_MANNEWSUFFIX=	${IMAKE_MAN_SUFFIX}
IMAKE_MANINSTALL?=	maninstall catinstall

_OPSYS_HAS_INET6=	no	# IPv6 is not standard
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	no	# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	none	# No shared libraries on Minix (yet)
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?= 	-b -V simple --suffix	# switch to patch(1) for backup suffix
_USE_RPATH=		no	# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk
