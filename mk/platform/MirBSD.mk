# $NetBSD: MirBSD.mk,v 1.6 2012/05/18 14:15:17 bsiegert Exp $
#
# Variable definitions for the MirOS BSD operating system.

ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	${MAKE}		# program which gets invoked by imake
PKGLOCALEDIR?=	share
PS?=		/bin/ps
RSH?=		/usr/bin/false	# not delivered with MirOS any more
SU?=		/usr/bin/su
TYPE?=		type				# Shell builtin

USERADD?=	${LOCALBASE}/sbin/useradd
GROUPADD?=	${LOCALBASE}/sbin/groupadd
_USER_DEPENDS=	user>=20000313:../../sysutils/user	#XXX make this work

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		0022
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table
MOTIF_TYPE_DEFAULT?=	openmotif
NOLOGIN?=		/sbin/nologin
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		/usr/bin/sudo /bin/mksh -c
ROOT_USER?=		root
ROOT_GROUP?=		wheel
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`

X11_TYPE?=		modular

_OPSYS_HAS_INET6=	yes	# IPv6 is standard
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	no	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	yes	# libossaudio is available
_OPSYS_LIBTOOL_REQD=	1.5.22nb5
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-V simple -z 	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

BUILDLINK_TRANSFORM+=	rm:-ldl	# libdl.a is an empty static library

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

.if (${MACHINE_ARCH} == "i386")
DEFAULT_SERIAL_DEVICE?=	/dev/tty00
SERIAL_DEVICES?=	/dev/tty00 \
			/dev/tty01
.elif (${MACHINE_ARCH} == "sparc")
DEFAULT_SERIAL_DEVICE?=	/dev/ttya
SERIAL_DEVICES?=	/dev/ttya \
			/dev/ttyb
.else
DEFAULT_SERIAL_DEVICE?=	/dev/null
SERIAL_DEVICES?=	/dev/null
.endif

PKG_HAVE_KQUEUE=	# defined

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax
