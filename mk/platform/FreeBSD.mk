# $NetBSD: FreeBSD.mk,v 1.40 2024/03/16 22:55:42 nia Exp $
#
# Variable definitions for the FreeBSD operating system.

BRANDELF?=	/usr/bin/brandelf		# used by linux compat layer
ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	${MAKE}		# program which gets invoked by imake
IMAKEOPTS+=	-DBuildHtmlManPages=NO
PKGLOCALEDIR?=	share
PS?=		/bin/ps
PW?=		/usr/sbin/pw
SU?=		/usr/bin/su
TYPE?=		type				# Shell builtin

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		0022
.if ${OBJECT_FMT} == "ELF"
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table
.else
EXPORT_SYMBOLS_LDFLAGS?=-Wl,--export-dynamic
.endif
MOTIF_TYPE_DEFAULT?=	motif	# default 2.0 compatible libs type
NOLOGIN?=		/sbin/nologin
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_USER?=		root
ROOT_GROUP?=	wheel
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`
ULIMIT_CMD_cputime?=	ulimit -t `ulimit -H -t`

_OPSYS_EMULDIR.freebsd=	# empty
_OPSYS_EMULDIR.linux=	/compat/linux

_OPSYS_SYSTEM_RPATH?=	/lib:/usr/lib	# STANDARD_LIBRARY_PATH (from rtld.h)
_OPSYS_LIB_DIRS?=	/lib /usr/lib
_OPSYS_INCLUDE_DIRS?=	/usr/include

.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	yes	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	${_OPSYS_SHLIB_TYPE_cmd:sh}	# shared library type
_OPSYS_SHLIB_TYPE_cmd=	\
	output=`/usr/bin/file /sbin/sysctl`;	\
	case $$output in			\
	*ELF*dynamically*)	echo ELF ;;	\
	*shared*library*)	echo a.out ;;	\
	*dynamically*)		echo a.out ;;	\
	*)			echo ELF ;;	\
	esac
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-V simple -b 	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

DEFAULT_SERIAL_DEVICE?=	/dev/cuaa0
SERIAL_DEVICES?=	/dev/cuaa0

# check for kqueue(2) support
.if exists(/usr/include/sys/event.h)
OPSYS_HAS_KQUEUE=	# defined
.endif

# check for posix_spawn(3) support, added in FreeBSD-8.0
.if exists(/usr/include/spawn.h)
OPSYS_HAS_POSIX_SPAWN=	# defined
.endif

OPSYS_HAS_SENDFILE=	# defined

# Register support for SSP on x86 architectures
.if (${MACHINE_ARCH} == "i386") || \
    (${MACHINE_ARCH} == "x86_64")
_OPSYS_SUPPORTS_SSP=	yes
.endif

_OPSYS_SUPPORTS_CTF=		yes # Compact Type Format conversion.
_OPSYS_SUPPORTS_CWRAPPERS=	yes
_OPSYS_CAN_CHECK_SHLIBS=	yes # use readelf in check/bsd.check-vars.mk
_OPSYS_CAN_CHECK_SSP=		no  # only supports libssp at this time

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax
