# $NetBSD: HPUX.mk,v 1.5 2007/04/29 11:54:25 tnn Exp $
#
# Variable definitions for the HP-UX operating system.

CPP?=		/opt/langtools/lbin/cpp
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
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
NOLOGIN?=		/etc/nologin
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_USER?=		root
ROOT_GROUP?=		sys
TOUCH_FLAGS?=				# touch doesn't understand -f
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`
# imake installs manpages in weird places
# these values from /usr/X11R6/lib/X11/config/NetBSD.cf
IMAKE_MAN_SOURCE_PATH=	man/cat
IMAKE_MAN_SUFFIX=	1
IMAKE_LIBMAN_SUFFIX=	3
IMAKE_FILEMAN_SUFFIX=	4
IMAKE_GAMEMAN_SUFFIX=	6
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}4
IMAKE_GAMEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}6
IMAKE_MANNEWSUFFIX=	1
IMAKE_MANINSTALL?=	maninstall catinstall

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

# flags passed to the linker to extract all symbols from static archives.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,-tools2-HPUX-fixme
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,-tools3-HPUX-fixme

DEFAULT_SERIAL_DEVICE?=	/dev/tty1p0
SERIAL_DEVICES?=	/dev/tty0p0 \
			/dev/tty1p0

_INCOMPAT_ICONV=   HPUX-*-*

# sysutils/fam is not usable on HP-UX.
FAM_DEFAULT?=		gamin

# mit-krb5 is builtin, and heimdal doesn't build.
KRB5_DEFAULT?=		mit-krb5

# Builtin openssl and zlib have issues. Prefer pkgsrc's until we know which
# versions work.
PREFER.openssl?=	pkgsrc
PREFER.zlib?=		pkgsrc

.if defined(OS_VERSION) && ${OS_VERSION} == "11.11" && \
    !defined(BUILDING_POSIX_HEADERS) && !make(bootstrap-register)
.include "../../pkgtools/posix_headers/buildlink3.mk"
.endif

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U}	# install(1) option to strip
