# $NetBSD: Darwin.mk,v 1.28 2007/12/16 12:36:28 tron Exp $
#
# Variable definitions for the Darwin operating system.

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
CPP_PRECOMP_FLAGS?=	-no-cpp-precomp	# use the GNU cpp, not the OS X cpp
.endif
DEF_UMASK?=		0022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
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
_USER_DEPENDS=		user>=20040801:../../sysutils/user_darwin

# imake installs manpages in weird places
# these values from /usr/X11R6/lib/X11/config/Imake.tmpl
IMAKE_MAN_SOURCE_PATH=	man/man
IMAKE_MAN_SUFFIX=	1
IMAKE_LIBMAN_SUFFIX=	3
IMAKE_FILEMAN_SUFFIX=	5
IMAKE_GAMEMAN_SUFFIX=	6
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_GAMEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}6
IMAKE_MANNEWSUFFIX=	${IMAKE_MAN_SUFFIX}
IMAKE_MANINSTALL?=	maninstall catinstall

_OPSYS_EMULDIR.darwin=	# empty

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

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-Wl,-x} # cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

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

# If games are to be installed setgid, then SETGIDGAME is set to 'yes'
# (it defaults to 'no' as per defaults/mk.conf).
# Set the group and mode to meaningful values in that case (defaults to
# BINOWN, BINGRP and BINMODE as per defaults/mk.conf).
# FIXME: Adjust to work on this system and enable the lines below.
#.if !(empty(SETGIDGAME:M[yY][eE][sS]))
#GAMEOWN=		games
#GAMEGRP=		games
#GAMEMODE=		2555
#GAMEDIRMODE=		0775
#.endif
