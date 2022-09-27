# $NetBSD: SunOS.mk,v 1.84 2022/09/27 08:46:33 jperkin Exp $
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

CATMAN_SECTION_SUFFIX?=	yes
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
ULIMIT_CMD_cputime?=	ulimit -t `${SETENV} LC_MESSAGES=C ulimit -H -t`
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

# Use SMF by default if available.
.if ${OPSYS_VERSION} >= 051000
INIT_SYSTEM?=		smf
.endif

# Comes with a builtin implementation based on mit-krb5
KRB5_DEFAULT?=		mit-krb5

# Builtin defaults which make sense for this platform.
_OPSYS_PREFER.getopt?=		native
_OPSYS_PREFER.libexecinfo?=	native
_OPSYS_PREFER.openssl?=		pkgsrc
_OPSYS_PREFER.solaris-pam?=	native

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

_OPSYS_MISSING_FEATURES=	asprintf

.if !exists(/usr/include/err.h)
_OPSYS_MISSING_FEATURES+=	err
.endif

.if ${OPSYS_VERSION} < 051100
_OPSYS_MISSING_FEATURES+=	strnlen
.endif

_PATCH_CAN_BACKUP=	yes		# native patch(1) can make backups
_PATCH_BACKUP_ARG?= 	-b -V simple -z	# switch to patch(1) for backup suffix
_USE_RPATH=		yes		# add rpath to LDFLAGS

# Remove flags specific to GNU ld.
BUILDLINK_TRANSFORM+=	rm:-Wl,--as-needed
BUILDLINK_TRANSFORM+=	rm:-Wl,--disable-new-dtags
BUILDLINK_TRANSFORM+=	rm:-Wl,--enable-new-dtags
BUILDLINK_TRANSFORM+=	rm:-Wl,--export-dynamic
BUILDLINK_TRANSFORM+=	rm:-Wl,--gc-sections
BUILDLINK_TRANSFORM+=	rm:-Wl,--no-as-needed
BUILDLINK_TRANSFORM+=	rm:-Wl,--warn-common
BUILDLINK_TRANSFORM+=	rm:-Wl,--warn-shared-textrel
BUILDLINK_TRANSFORM+=	rm:-Wl,-O1
BUILDLINK_TRANSFORM+=	rm:-Wl,-O2
BUILDLINK_TRANSFORM+=	rm:-Wl,-export-dynamic
BUILDLINK_TRANSFORM+=	rm:-export-dynamic

# Convert GNU ld flags to native SunOS ld flags where possible.
BUILDLINK_TRANSFORM+=	opt:-Wl,--rpath:-Wl,-R

# Remove GCC-specific flags if using clang
.if ${PKGSRC_COMPILER} == "clang"
BUILDLINK_TRANSFORM+=	rm:-mimpure-text
.endif

# The native curses implementations are reasonably old and can cause lots of
# issues with software which assumes newer interfaces, so it's easier to just
# use pkgsrc curses at this point.  Both curses and terminfo should be in sync
# otherwise it's possible to end up with conflicting buildlink transforms.
#
_INCOMPAT_CURSES=		SunOS-*-*
_OPSYS_PREFER.terminfo?=	pkgsrc

# Solaris has /usr/include/iconv.h, but it's not GNU iconv, so mark it
# incompatible.
_INCOMPAT_ICONV=	SunOS-*-*

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

PKG_TOOLS_BIN?=		${LOCALBASE}/sbin

LIBABISUFFIX.sparc64=	/sparcv9
LIBABISUFFIX.x86_64=	/amd64
LIBABISUFFIX?=		${LIBABISUFFIX.${MACHINE_ARCH}}
_OPSYS_SYSTEM_RPATH?=	/lib${LIBABISUFFIX}:/usr/lib${LIBABISUFFIX}
_OPSYS_LIB_DIRS?=	/lib${LIBABISUFFIX} /usr/lib${LIBABISUFFIX}
_OPSYS_INCLUDE_DIRS?=	/usr/include

# Sun Studio support is untested at this time, but would be strongly desired.
.if ${PKGSRC_COMPILER} != "sunpro"
_OPSYS_SUPPORTS_CWRAPPERS=	yes
.endif

_OPSYS_SUPPORTS_CTF=		yes # Compact Type Format conversion.
_OPSYS_SUPPORTS_FORTIFY=	yes # Requires GCC
_OPSYS_SUPPORTS_MKTOOLS=	yes
_OPSYS_SUPPORTS_SSP?=		yes # Requires GCC
_OPSYS_CAN_CHECK_SHLIBS=	yes # Requires readelf

# The Solaris/illumos linker requires explicit library dependencies.
OPSYS_EXPLICIT_LIBDEPS=		yes

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
# FIXME: Adjust to work on this system and enable the lines below.
#_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax
