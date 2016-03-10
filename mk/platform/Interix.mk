# $NetBSD: Interix.mk,v 1.77 2016/03/10 16:58:19 jperkin Exp $
#
# Variable definitions for the Interix operating system.

# SHLIB BASE ADDRESSES:
#
# [tv] For reference, here's a list of shared library base address ranges used
# throughout pkgsrc to cope with the fact that Interix has no proper PIC
# support in the compiler.  This list will be kept updated for any new packages
# also needing special handling.
#
# Fortunately, libtool covers most of this, and uses a randomized base address
# selection as described below.  This randomized base address concept is used
# again in a couple other places.
#
# * = currently uses fixed default of 0x10000000 and needs something better
#     (this base address restricts how far sbrk() can go in memory, and of
#     course, collides with everything else, requiring runtime text relocs)
#
# pkg		start		end		slotsize	#slots
#
# <bsd.lib.mk>	0x50000000	0x6fffffff	0x00040000	2048
# libtool-base	0x50000000	0x6fffffff	0x00040000	2048
# netpbm	0x6b000000	0x6cffffff	0x00100000	32
# openssl	0x5e000000	0x5fffffff	0x00100000	32
# perl5		*
# python22	*
# python23	*
# python24	*
# ruby16	0x50000000	0x6fffffff	0x00040000	2048
#   (main lib)	0x48000000
# ruby18	0x50000000	0x6fffffff	0x00040000	2048
#   (main lib)	0x48000000
# zsh		*

# ADDITIONAL NOTES:
#
# * It appears that www/curl 1.15.0+ has support for SIOCGIFADDR via
#   an undocumented ioctl interface.  It may be worthwhile to look at
#   adding that hack into a more proper <net/if.h> to be supplied by
#   pkgsrc's compiler wrappers.  [tv]

###
### Overrides to standard BSD .mk files
###

# "catinstall" not yet supported as there's no shipped [gn]roff
MANINSTALL=	maninstall
MAKE_FLAGS+=	MKCATPAGES=no NOLINT=1

###
### Alternate defaults to global pkgsrc settings, to help avoid
### some of the excessive Interix fork(2) overhead, and reduce the
### amount of settings required in the user's mk.conf
###

# NetBSD's faster, vfork-capable shell (not yet in pkgsrc)
.if exists(${PREFIX}/bin/nbsh)
TOOLS_SHELL?=		${PREFIX}/bin/nbsh
WRAPPER_SHELL?=		${PREFIX}/bin/nbsh
.endif

INSTALL?=		${PREFIX}/bin/install-sh
SED?=			${PREFIX}/bin/nbsed

###
### Platform definitions common to pkgsrc/mk/platform/*.mk
###

ECHO_N?=	/bin/printf %s			# does not support "echo -n"
IMAKE_MAKE?=	${MAKE}		# program which gets invoked by imake
IMAKEOPTS+=	-DBuildHtmlManPages=NO
PKGLOCALEDIR?=	share
PS?=		/bin/ps
SU?=		/bin/su
TYPE?=		type				# Shell builtin

USERADD?=		${LOCALBASE}/sbin/useradd
GROUPADD?=		${LOCALBASE}/sbin/groupadd
_PKG_USER_HOME?=	# empty by default
_USER_DEPENDS=		user-interix>=20130712:../../sysutils/user_interix

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		002
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table

MOTIF_TYPE_DEFAULT?=	motif	# default 2.0 compatible libs type
NOLOGIN?=		/bin/false
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
PKGDIRMODE?=		775
# ROOT_USER might be numeric in the special case of Administrator; canonify it:
ROOT_CMD?=		${SU} - "$$(id -un ${ROOT_USER})" -c
ROOT_USER?=		${BINOWN}
ROOT_GROUP?=		+Administrators # or native language equivalent
TOUCH_FLAGS?=
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -v `ulimit -H -v`

_OPSYS_SYSTEM_RPATH?=	/usr/lib
_OPSYS_LIB_DIRS?=	/usr/lib
_OPSYS_INCLUDE_DIRS?=	/usr/include

.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=	5.8.3nb1 # base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF	# shared lib type - not exactly true, but near enough
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-b -V simple -z	# switch to patch(1) for backup suffix
_USE_RPATH=		yes	# add rpath to LDFLAGS

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

DEFAULT_SERIAL_DEVICE?=	/dev/tty00
SERIAL_DEVICES?=	/dev/tty00 /dev/tty01 /dev/tty02 /dev/tty03

_OPSYS_CAN_CHECK_SHLIBS=	no # can't use readelf in check/bsd.check-vars.mk

# poll(2) is broken; try to work around it by making autoconf believe
# it's missing.  (Packages without autoconf will need explicit fixing.)
CONFIGURE_ENV+=		${GNU_CONFIGURE:Dac_cv_header_poll_h=no ac_cv_func_poll=no}

# Interix has a hstrerror(3), but it's a macro, not a function.
CONFIGURE_ENV+=		${GNU_CONFIGURE:Dac_cv_func_hstrerror=yes}

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
_OPSYS_MAX_CMDLEN_CMD=	${ECHO} 262144

#
# Interix has dlopen(3) and family, they are provided by gcc (Interix-6.1).
# pkgsrc'c check is broken.
#
IS_BUILTIN.dl=		yes
