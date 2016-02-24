# $NetBSD: Darwin.mk,v 1.78 2016/02/24 14:59:56 jperkin Exp $
#
# Variable definitions for the Darwin operating system.

# OS, Kernel, Xcode Version
# Note that Xcode gets updates on older systems sometimes.
# pkgsrc generally expects that the most up-to-date xcode available for
# an OS version is installed
#
# Codename	OS	Kernel	Xcode
# Cheetah	10.0.x	1.3.1
# Puma		10.1	1.4.1
#		10.1.x	5.x.y
# Jaguar	10.2.x	6.x.y
# Panther	10.3.x	7.x.y
# Tiger		10.4.x	8.x.y	2.x (gcc 4.0, 4.0.1 from 2.2)
# Leopard	10.5.x	9.x.y	3.x (gcc 4.0.1, 4.0.1 and 4.2.1 from 3.1)
# Snow Leopard	10.6.x	10.x.y	3.2+ (gcc 4.0.1 and 4.2.1)
# Lion		10.7.x	11.x.y	4.1 (llvm gcc 4.2.1)
# Mountain Lion	10.8.x	12.x.y	4.5 (llvm gcc 4.2.1)
# Mavericks	10.9.x	13.x.y	6 (llvm clang 6.0)
# Yosemite	10.10.x	14.x.y	6 (llvm clang 6.0)
# El Capitan	10.11.x	15.x.y	7 (llvm clang 7.0)

# Tiger (and earlier) use Xfree 4.4.0 (and earlier)
.if empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
X11_TYPE?=	native
.endif

.if !defined(CPP) || ${CPP} == "cpp"
CPP=		${CC} -E ${CPP_PRECOMP_FLAGS}
.endif
.if empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
ECHO_N?=	/bin/echo -n
.else
ECHO_N?=	${ECHO} -n
.endif
LDD?=		/usr/bin/otool -L
IMAKE_MAKE?=	${MAKE}		# program which gets invoked by imake
PKGLOCALEDIR?=	share
PS?=		/bin/ps
# XXX: default from defaults/mk.conf.  Verify/correct for this platform
# and remove this comment.
SU?=		/usr/bin/su
TYPE?=		type				# Shell builtin
IMAKEOPTS+=	-DBuildHtmlManPages=NO
.if defined(UNPRIVILEGED) && !empty(UNPRIVILEGED:M[Yy][Ee][Ss])
IMAKEOPTS+=	-DInstallFlags=-c		# do not set user or group
.endif

.if !defined(PKGSRC_COMPILER) || !empty(PKGSRC_COMPILER:Mgcc)
# don't look in "/usr/local/include" before "/usr/include".
CPP_PRECOMP_FLAGS?=	-isystem /usr/include
# don't symlink to /usr/bin/gcc since the latter is a wrapper that tries
# evoke the real (architecture-dependent) gcc binary in the same place
# which fails when called via a symlink from a different directory
COMPILER_USE_SYMLINKS?=	no
.endif
DEF_UMASK?=		0022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
MOTIF_TYPE_DEFAULT?=	motif	# default 2.0 compatible libs type
NOLOGIN?=		/usr/bin/false
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		/usr/bin/sudo ${SH} -c
ROOT_GROUP?=		wheel
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`

GROUPADD?=		${LOCALBASE}/sbin/groupadd
USERADD?=		${LOCALBASE}/sbin/useradd
_PKG_USER_HOME?=	/var/empty	# to match other system accounts
_USER_DEPENDS=		user-darwin>=20130712:../../sysutils/user_darwin

_OPSYS_EMULDIR.darwin=	# empty

_OPSYS_SYSTEM_RPATH?=	/usr/lib
_OPSYS_LIB_DIRS?=	/usr/lib

OSX_VERSION!=		sw_vers -productVersion
.  if ${OSX_VERSION:R:R} != ${OSX_VERSION:R}
OSX_VERSION:=		${OSX_VERSION:R}
.  endif
MAKEFLAGS+=		OSX_VERSION=${OSX_VERSION:Q}

#
# From Xcode 5 onwards system headers are no longer installed by default
# into /usr/include, so we need to query their location if /usr/include is
# not available.
#
# Use current system version SDK (avoid newer SDKs).
#
.if exists(/usr/include/stdio.h)
_OPSYS_INCLUDE_DIRS?=	/usr/include
.elif exists(/usr/bin/xcrun)
OSX_SDK_PATH!=	/usr/bin/xcrun --sdk macosx${OSX_VERSION} --show-sdk-path 2>/dev/null || echo /nonexistent
.  if exists(${OSX_SDK_PATH}/usr/include/stdio.h)
_OPSYS_INCLUDE_DIRS?=	${OSX_SDK_PATH}/usr/include
MAKEFLAGS+=		OSX_SDK_PATH=${OSX_SDK_PATH:Q}
.  else
PKG_FAIL_REASON+=	"No suitable Xcode SDK or Command Line Tools installed."
.  endif
.endif

.if ${OS_VERSION:R} >= 6
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	yes	# Java is standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=	5.8.0	# base version of perl required
_OPSYS_PTHREAD_AUTO=	yes	# -lpthread not needed for pthreads
_OPSYS_LINKER_RPATH_FLAG=	-L	# darwin has no rpath, use -L instead
_OPSYS_COMPILER_RPATH_FLAG=	-L	# compiler flag to pass rpaths to linker
_OPSYS_SHLIB_TYPE=	dylib	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-V simple -b -z	# switch to patch(1) for backup suffix
_USE_RPATH=		no	# don't add rpath to LDFLAGS

# Comes with a native mit-krb5 implementation
KRB5_DEFAULT?=		mit-krb5

#
# Builtin overrides.
#
.if !empty(OS_VERSION:M[56].*)
USE_BUILTIN.dl=		no	# Darwin-[56].* uses devel/dlcompat
.endif

# Builtin defaults which make sense for this platform.
_OPSYS_PREFER.libuuid?=		native	# system headers assume uuid_string_t
_OPSYS_PREFER.linux-pam?=	native
_OPSYS_PREFER.mit-krb5?=	native
.if ${OS_VERSION:R} >= 11
_OPSYS_PREFER.openssl?=		pkgsrc	# builtin deprecated from 10.7 onwards
.endif

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
.if empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,-force-load
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	
.else
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive
.endif

_OPSYS_CAN_CHECK_SHLIBS=	yes # check shared libraries using otool(1)

# OSX strip(1) tries to remove relocatable symbols and fails on certain
# objects, resulting in non-zero exit status.  We can't modify strip arguments
# (e.g. adding "-u -r" which would fix the issue) when using install -s so for
# now stripping is disabled in that mode.
_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-Wl,-x} # cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U}	# install(1) option to strip

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
_OPSYS_MAX_CMDLEN_CMD=	/usr/sbin/sysctl -n kern.argmax

# Darwin 7.7.x has poll() in libc, but no poll.h. Try to help GNU
# configure packages that break because of this by pretending that
# there is no poll().
.if defined(GNU_CONFIGURE)
.  if !exists(/usr/include/poll.h) && !exists(/usr/include/sys/poll.h)
CONFIGURE_ENV+=		ac_cv_func_poll=no
.  endif
.endif

# If the deployment target is not set explicitly, the linker in Tiger and prior
# versions running on PowerPC hosts defaults to a target of 10.1.
# Set the target for Tiger systems to be 10.4.
.if !empty(MACHINE_PLATFORM:MDarwin-8.*-powerpc)
MAKE_ENV+=	MACOSX_DEPLOYMENT_TARGET="10.4"
.endif

# El Capitan GM has a file system bug where a deep directory hierarchy can be
# created but not removed.  Avoid running a test which does exactly this.
# See https://openradar.appspot.com/radar?id=6160634819379200
.if defined(GNU_CONFIGURE) && !empty(OS_VERSION:M15.[01].0)
CONFIGURE_ENV+=		gl_cv_func_getcwd_abort_bug=no
.endif

# Use "/bin/ksh" for buildlink3 wrapper script to improve build performance.
.if (!empty(OS_VERSION:M9.*) || !empty(OS_VERSION:M1[0-2].*) || \
     !empty(OS_VERSION:M1[4-9].*)) && \
    exists(/bin/ksh)
WRAPPER_BIN_SH?=	/bin/ksh
.endif
