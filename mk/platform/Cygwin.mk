# $NetBSD: Cygwin.mk,v 1.11 2013/03/13 12:38:19 obache Exp $
#
# Variable definitions for the Windows with Cygwin.

###
### Platform definitions common to pkgsrc/mk/platform/*.mk
###

ECHO_N?=	${ECHO} -n
IMAKE_MAKE?=	${GMAKE}		# program which gets invoked by imake
IMAKEOPTS+=	-DBuildHtmlManPages=NO
PKGLOCALEDIR?=	share
PS?=		/bin/ps
SU?=		/bin/su
TYPE?=		type				# Shell builtin

USERADD?=		${LOCALBASE}/sbin/useradd
GROUPADD?=		${LOCALBASE}/sbin/groupadd
_PKG_USER_HOME?=	# empty by default
_USER_DEPENDS=		user>=20130313:../../sysutils/user_cygwin

CPP_PRECOMP_FLAGS?=	# unset
CONFIG_RPATH_OVERRIDE?=	config.rpath */config.rpath */*/config.rpath
DEF_UMASK?=		002
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table

MOTIF_TYPE_DEFAULT?=	motif	# default 2.0 compatible libs type
NOLOGIN?=		/bin/false
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
PKGDIRMODE?=		775
# ROOT_USER might be numeric in the special case of Administrator; canonify it:
ROOT_CMD?=		${SU} - "$$(${ID} -un ${ROOT_USER})" -c
ROOT_USER?=		${BINOWN}
ROOT_GROUP?=		Administrators
_IS_ROOT_CMD?=		( ${ID} -nG | ${GREP} -q 'Administrators' )
TOUCH_FLAGS?=
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -v `ulimit -H -v`

X11_TYPE?=		native

_OPSYS_EXE_SUFFIX=	.exe	# executables may have suffix
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=	5.8.3nb1 # base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	PEwin	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-b -V simple -z	# switch to patch(1) for backup suffix
_USE_RPATH=		no	# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

DEFAULT_SERIAL_DEVICE?=	/dev/ttyS0
SERIAL_DEVICES?=	/dev/ttyS0 /dev/ttyS1 /dev/ttyS2 /dev/ttyS3

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
_OPSYS_MAX_CMDLEN_CMD=	${ECHO} 262144

# check for requirement of uac-manifest.
.if !empty(OS_VARIANT:MCYGWIN_NT-[6-9].*)
_OPSYS_REQUIRE_UAC_MANIFEST=	yes
.endif

