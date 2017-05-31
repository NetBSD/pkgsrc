# $NetBSD: NetBSD.mk,v 1.50 2017/05/31 22:55:01 jlam Exp $
#
# Variable definitions for the NetBSD operating system.

# Needed for 1.6.1 and earlier due to rpcgen bugs and paths
.if defined(CPP) && ${CPP} == "cpp"
CPP=		/usr/bin/cpp
.endif
ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	${MAKE}		# program which gets invoked by imake
PKGLOCALEDIR?=	share
PS?=		/bin/ps
SU?=		/usr/bin/su
TYPE?=		type				# Shell builtin

USERADD?=	/usr/sbin/useradd
GROUPADD?=	/usr/sbin/groupadd

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		0022
.if ${OBJECT_FMT} == "ELF"
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table
.else
EXPORT_SYMBOLS_LDFLAGS?=-Wl,--export-dynamic
.endif
MOTIF_TYPE_DEFAULT?=	motif	# default 2.0 compatible libs type
NOLOGIN?=		/sbin/nologin
# This must be lazy and using :? evaluation doesn't work due to a make bugs.
PKG_TOOLS_BIN_cmd=	if [ -x ${LOCALBASE}/sbin/pkg_info ]; then echo ${LOCALBASE}/sbin; else echo /usr/sbin; fi
PKG_TOOLS_BIN?=		${PKG_TOOLS_BIN_cmd:sh}
ROOT_CMD?=		${SU} - root -c
ROOT_USER?=		root
ROOT_GROUP?=	wheel
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`
ULIMIT_CMD_cputime?=	ulimit -t `ulimit -H -t`

# Native X11 is only supported on NetBSD-5 and later.
# On NetBSD-5, native X11 has enough issues that we default
# to modular.
.if empty(MACHINE_PLATFORM:MNetBSD-[0-5].*)
X11_TYPE?=		native
.endif

_OPSYS_EMULDIR.aout=		/emul/aout
_OPSYS_EMULDIR.darwin=		/emul/darwin
_OPSYS_EMULDIR.freebsd=		/emul/freebsd
_OPSYS_EMULDIR.hpux=		/emul/hpux
_OPSYS_EMULDIR.irix=		/emul/irix
_OPSYS_EMULDIR.linux=		/emul/linux
_OPSYS_EMULDIR.linux32=		/emul/linux32
_OPSYS_EMULDIR.netbsd=		# empty
_OPSYS_EMULDIR.netbsd32=	/emul/netbsd32
_OPSYS_EMULDIR.osf1=		/emul/osf1
_OPSYS_EMULDIR.solaris=		/emul/svr4
_OPSYS_EMULDIR.solaris32=	/emul/svr4_32
_OPSYS_EMULDIR.sunos=		/emul/sunos

_OPSYS_SYSTEM_RPATH?=		/usr/lib
_OPSYS_LIB_DIRS?=		/usr/lib
_OPSYS_INCLUDE_DIRS?=		/usr/include

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
_PATCH_BACKUP_ARG?=	-V simple --suffix # switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

# for programs which use dlopen()
# not necessary since 1.6 (shared libs are linked against libgcc_pic)
.if !empty(OS_VERSION:M1.5*)
LINK_ALL_LIBGCC_HACK=	-Wl,--whole-archive -lgcc -Wl,--no-whole-archive
.endif

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

.if (${MACHINE_ARCH} == alpha)
DEFAULT_SERIAL_DEVICE?=	/dev/ttyC0
SERIAL_DEVICES?=	/dev/ttyC0 \
			/dev/ttyC1
.elif (${MACHINE_ARCH} == "i386")
DEFAULT_SERIAL_DEVICE?=	/dev/tty00
SERIAL_DEVICES?=	/dev/tty00 \
			/dev/tty01
.elif (${MACHINE_ARCH} == m68k)
DEFAULT_SERIAL_DEVICE?=	/dev/tty00
SERIAL_DEVICES?=	/dev/tty00 \
			/dev/tty01
.elif (${MACHINE_ARCH} == mipsel)
DEFAULT_SERIAL_DEVICE?=	/dev/ttyC0
SERIAL_DEVICES?=	/dev/ttyC0 \
			/dev/ttyC1
.elif (${MACHINE_ARCH} == "sparc")
DEFAULT_SERIAL_DEVICE?=	/dev/ttya
SERIAL_DEVICES?=	/dev/ttya \
			/dev/ttyb
.else
DEFAULT_SERIAL_DEVICE?=	/dev/null
SERIAL_DEVICES?=	/dev/null
.endif

# Add -mieee to CFLAGS and FFLAGS for NetBSD->=1.5V-alpha
.for __tmp__ in 1.5[V-Z] 1.5[A-Z][A-Z]* 1.[6-9]* [2-9].*
.  if ${MACHINE_PLATFORM:MNetBSD-${__tmp__}-alpha} != ""
CFLAGS+=	-mieee
FFLAGS+=	-mieee
.  endif	# MACHINE_PLATFORM
.endfor		# __tmp__

# check for kqueue(2) support, added in NetBSD-1.6J
.if exists(/usr/include/sys/event.h)
PKG_HAVE_KQUEUE=	# defined
.endif

# Register support for FORTIFY (with GCC)
_OPSYS_SUPPORTS_FORTIFY=yes

# Register support for PIE on supported architectures (with GCC)
.if (${MACHINE_ARCH} == "i386") || \
    (${MACHINE_ARCH} == "x86_64")
_OPSYS_SUPPORTS_MKPIE=	yes
.endif

# Register support for RELRO on supported architectures (with GCC)
.if (${MACHINE_ARCH} == "i386") || \
    (${MACHINE_ARCH} == "x86_64")
_OPSYS_SUPPORTS_RELRO=	yes
.endif

# Register support for SSP on most architectures (with GCC)
.if (${MACHINE_ARCH} != "alpha") && \
    (${MACHINE_ARCH} != "hppa") && \
    (${MACHINE_ARCH} != "ia64") && \
    (${MACHINE_ARCH} != "mips")
_OPSYS_SUPPORTS_SSP=	yes
.endif

_OPSYS_SUPPORTS_CWRAPPERS=	yes

_OPSYS_CAN_CHECK_SHLIBS=	yes # use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax
