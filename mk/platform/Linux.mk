# $NetBSD: Linux.mk,v 1.59 2014/02/20 11:03:09 jperkin Exp $
#
# Variable definitions for the Linux operating system.

ECHO_N?=	${ECHO} -n
.if defined(X11_TYPE) && ${X11_TYPE} == "native"
IMAKE_MAKE?=	${GMAKE}	# program which gets invoked by imake
IMAKE_TOOLS=		gmake	# extra tools required when we use imake
.endif
IMAKEOPTS+=	-DBuildHtmlManPages=NO
PKGLOCALEDIR?=	share
PS?=		/bin/ps
# XXX: default from defaults/mk.conf.  Verify/correct for this platform
# and remove this comment.
.if exists(/usr/bin/su)
SU?=		/usr/bin/su
.else
SU?=		/bin/su
.endif
TYPE?=		type			# Shell builtin

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
GROUPADD?=		/usr/sbin/groupadd
MOTIF_TYPE_DEFAULT?=	motif	# default 2.0 compatible libs type
.if exists(/etc/ssdlinux_version)
NOLOGIN?=		/sbin/nologin
.else
NOLOGIN?=		/bin/false
.endif
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
.if exists(/etc/ssdlinux_version)
ROOT_GROUP?=		wheel
.else
ROOT_GROUP?=		root
.endif
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`
USERADD?=		/usr/sbin/useradd

_OPSYS_EMULDIR.linux=	# empty
_OPSYS_EMULDIR.linux32=	# empty

# Support Debian/Ubuntu's multiarch hierarchy.
.if exists(/etc/debian_version)
.if !empty(MACHINE_ARCH:Mx86_64)
_OPSYS_SYSTEM_RPATH=	/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}:/lib/x86_64-linux-gnu:/usr/lib/x86_64-linux-gnu
_OPSYS_LIB_DIRS?=	/lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX} /lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu
.endif
.if !empty(MACHINE_ARCH:Mi386)
_OPSYS_SYSTEM_RPATH=	/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}:/lib/i386-linux-gnu:/usr/lib/i386-linux-gnu
_OPSYS_LIB_DIRS?=	/lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX} /lib/i386-linux-gnu /usr/lib/i386-linux-gnu
.endif
.if !empty(MACHINE_ARCH:Marm*)
_OPSYS_SYSTEM_RPATH=	/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}:/lib/arm-linux-gnueabi:/usr/lib/arm-linux-gnueabi
_OPSYS_LIB_DIRS?=	/lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX} /lib/arm-linux-gnueabi /usr/lib/arm-linux-gnueabi
.endif
.else
_OPSYS_SYSTEM_RPATH=	/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}
_OPSYS_LIB_DIRS?=	/lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX}
.endif
_OPSYS_INCLUDE_DIRS?=	/usr/include

# These are libc builtins
_OPSYS_PREFER.getopt?=		native
_OPSYS_PREFER.gettext?=		native
_OPSYS_PREFER.iconv?=		native
_OPSYS_PREFER.libexecinfo?=	native
_OPSYS_PREFER.libinotify?=	native
_OPSYS_PREFER.sysexits?=	native

.if exists(/usr/include/netinet6) || exists(/usr/include/linux/in6.h)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	no	# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is unavailable
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

_OPSYS_CAN_CHECK_SHLIBS=	yes # use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
.if exists(/usr/bin/getconf)
_OPSYS_MAX_CMDLEN_CMD?=	/usr/bin/getconf ARG_MAX
.endif

.if ${MACHINE_ARCH} == "x86_64"
ABI?=		64
LIBABISUFFIX?=	64
.endif

## Use _CMD so the command only gets run when needed!
.if exists(/lib${LIBABISUFFIX}/libc.so.6)
_GLIBC_VERSION_CMD=	/lib${LIBABISUFFIX}/libc.so.6 --version | \
				sed -ne's/^GNU C.*version \(.*\),.*$$/\1/p'
GLIBC_VERSION=		${_GLIBC_VERSION_CMD:sh}
.endif

# If this is defined pass it to the make process. 
.if defined(NOGCCERROR)
MAKE_ENV+=	NOGCCERROR=true
.endif
