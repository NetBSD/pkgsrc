# $NetBSD: GNUkFreeBSD.mk,v 1.4 2016/03/10 16:58:19 jperkin Exp $
#
# Variable definitions for the Debian GNU/kFreeBSD operating system.

ECHO_N?=	${ECHO} -n
.if defined(X11_TYPE) && ${X11_TYPE} == "native"
IMAKE_MAKE?=	${GMAKE}	# program which gets invoked by imake
IMAKE_TOOLS=		gmake	# extra tools required when we use imake
.endif
IMAKEOPTS+=	-DBuildHtmlManPages=NO
PKGLOCALEDIR?=	share
PS?=		/bin/ps
SU?=		/bin/su
TYPE?=		type			# Shell builtin

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
GROUPADD?=		/usr/sbin/groupadd
MOTIF_TYPE_DEFAULT?=	motif	# default 2.0 compatible libs type
NOLOGIN?=		/usr/sbin/nologin
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		root
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`
ULIMIT_CMD_cputime?=	ulimit -t `ulimit -H -t`
USERADD?=		/usr/sbin/useradd

.if !empty(MACHINE_ARCH:Mx86_64)
_OPSYS_SYSTEM_RPATH=	/lib:/usr/lib:/lib/x86_64-kfreebsd-gnu:/usr/lib/x86_64-kfreebsd-gnu
_OPSYS_LIB_DIRS?=	/lib /usr/lib /lib/x86_64-kfreebsd-gnu /usr/lib/x86_64-kfreebsd-gnu
.endif
.if !empty(MACHINE_ARCH:Mi386)
_OPSYS_SYSTEM_RPATH=	/lib:/usr/lib:/lib/i386-kfreebsd-gnu:/usr/lib/i386-kfreebsd-gnu
_OPSYS_LIB_DIRS?=	/lib /usr/lib /lib/i386-kfreebsd-gnu /usr/lib/i386-kfreebsd-gnu
.endif
_OPSYS_INCLUDE_DIRS?=	/usr/include

# These are libc builtins
_OPSYS_PREFER.getopt?=		native
_OPSYS_PREFER.gettext?=		native
_OPSYS_PREFER.iconv?=		native
_OPSYS_PREFER.sysexits?=	native

_OPSYS_HAS_INET6=	yes	# IPv6 is standard
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is unavailable
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?= 	-b -V simple -z	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

_OPSYS_CAN_CHECK_SHLIBS=	yes # use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
.if exists(/usr/bin/getconf)
_OPSYS_MAX_CMDLEN_CMD?=	/usr/bin/getconf ARG_MAX
.endif

# If this is defined pass it to the make process. 
.if defined(NOGCCERROR)
MAKE_ENV+=	NOGCCERROR=true
.endif
