# $NetBSD: Linux.mk,v 1.82 2020/01/24 12:36:28 nia Exp $
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
ULIMIT_CMD_cputime?=	ulimit -t `ulimit -H -t`
USERADD?=		/usr/sbin/useradd

_OPSYS_EMULDIR.linux=	# empty
_OPSYS_EMULDIR.linux32=	# empty

# Support Debian/Ubuntu's multiarch hierarchy.
.if exists(/etc/debian_version)
.  if !empty(MACHINE_ARCH:Mx86_64)
_OPSYS_SYSTEM_RPATH=	/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}:/lib/x86_64-linux-gnu:/usr/lib/x86_64-linux-gnu
_OPSYS_LIB_DIRS?=	/lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX} /lib/x86_64-linux-gnu /usr/lib/x86_64-linux-gnu
.  endif
.  if !empty(MACHINE_ARCH:Mi386)
_OPSYS_SYSTEM_RPATH=	/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}:/lib/i386-linux-gnu:/usr/lib/i386-linux-gnu
_OPSYS_LIB_DIRS?=	/lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX} /lib/i386-linux-gnu /usr/lib/i386-linux-gnu
.  endif
.  if !empty(MACHINE_ARCH:Marm*)
.    if exists(/etc/ld.so.conf.d/arm-linux-gnueabihf.conf)
_OPSYS_SYSTEM_RPATH=	/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}:/lib/arm-linux-gnueabihf:/usr/lib/arm-linux-gnueabihf
_OPSYS_LIB_DIRS?=	/lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX} /lib/arm-linux-gnueabihf /usr/lib/arm-linux-gnueabihf
.    else
_OPSYS_SYSTEM_RPATH=	/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}:/lib/arm-linux-gnueabi:/usr/lib/arm-linux-gnueabi
_OPSYS_LIB_DIRS?=	/lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX} /lib/arm-linux-gnueabi /usr/lib/arm-linux-gnueabi
.    endif
.  endif
.  if !empty(MACHINE_ARCH:Maarch64)
LIBABISUFFIX?=		/aarch64-linux-gnu
_OPSYS_SYSTEM_RPATH=	/lib:/usr/lib:/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}
_OPSYS_LIB_DIRS?=	/lib /usr/lib /lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX}
.  endif
.  if !empty(MACHINE_ARCH:Mpowerpc64le)
LIBABISUFFIX?=		/powerpc64le-linux-gnu
_OPSYS_SYSTEM_RPATH=	/lib:/usr/lib:/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}
_OPSYS_LIB_DIRS?=	/lib /usr/lib /lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX}
.  endif
.else
_OPSYS_SYSTEM_RPATH=	/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}
_OPSYS_LIB_DIRS?=	/lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX}
.endif
_OPSYS_INCLUDE_DIRS?=	/usr/include

.if !empty(OS_VARIANT:Mchromeos)
_OPSYS_LIB_DIRS+=	/usr/local/lib
_OPSYS_INCLUDE_DIRS+=	/usr/local/include
.endif

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

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

_OPSYS_SUPPORTS_CWRAPPERS=	yes

_OPSYS_CAN_CHECK_SHLIBS=	yes # use readelf in check/bsd.check-vars.mk
_OPSYS_CAN_CHECK_SSP=		no  # only supports libssp at this time

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
.if exists(/usr/bin/getconf)
_OPSYS_MAX_CMDLEN_CMD?=	/usr/bin/getconf ARG_MAX
.endif

# Register support for FORTIFY (with GCC).  Linux only supports FORTIFY
# when optimisation is enabled, otherwise warnings are issued.
.if !empty(CFLAGS:M-O*)
_OPSYS_SUPPORTS_FORTIFY=yes
.endif

# Register support for RELRO on supported architectures
.if (${MACHINE_ARCH} == "i386") || \
    (${MACHINE_ARCH} == "x86_64")
_OPSYS_SUPPORTS_RELRO=	yes
.endif

# Register support for SSP on x86 architectures
.if (${MACHINE_ARCH} == "i386") || \
    (${MACHINE_ARCH} == "x86_64")
_OPSYS_SUPPORTS_SSP=	yes
.endif

.if ${MACHINE_ARCH} == "x86_64"
ABI?=		64
LIBABISUFFIX?=	64
.endif

.if ${MACHINE_ARCH} == "powerpc64le"
ABI?=		64
LIBABISUFFIX?=	64
.endif

.if ${MACHINE_ARCH} == "aarch64"
# No toolchain multilib support yet?
# ABI?=		64
LIBABISUFFIX?=	64
.endif

# When building 32-bit packages on x86_64 GNU ld isn't smart enough to
# figure out the target architecture based on the objects so we need to
# explicitly set it.
.if ${HOST_MACHINE_ARCH} == "x86_64" && ${MACHINE_ARCH} == "i386"
_WRAP_EXTRA_ARGS.LD+=	-m elf_i386
CWRAPPERS_APPEND.ld+=	-m elf_i386
.endif

.for _glibc_path in ${_OPSYS_LIB_DIRS}
.  if exists(${_glibc_path}/libc.so.6)
## Use _CMD so the command only gets run when needed!
_GLIBC_VERSION_CMD=	${_glibc_path}/libc.so.6 --version | \
				sed -ne's/^GNU C.*version \(.*\),.*$$/\1/p'
GLIBC_VERSION=		${_GLIBC_VERSION_CMD:sh}
.  endif
.endfor

# If this is defined pass it to the make process. 
.if defined(NOGCCERROR)
MAKE_ENV+=	NOGCCERROR=true
.endif
