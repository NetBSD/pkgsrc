# $NetBSD: Darwin.mk,v 1.9 2005/05/03 15:10:59 jlam Exp $
#
# Variable definitions for the Darwin operating system.

AWK?=		/usr/bin/awk
BASENAME?=	/usr/bin/basename
CAT?=		/bin/cat
CHMOD?=		/bin/chmod
CHOWN?=		/usr/sbin/chown
CHGRP?=		/usr/bin/chgrp
CMP?=		/usr/bin/cmp
CP?=		/bin/cp
.if !defined(CPP) || ${CPP} == "cpp"
CPP=		${CC} -E ${CPP_PRECOMP_FLAGS}
.endif
CUT?=		/usr/bin/cut
DATE?=		/bin/date
DIRNAME?=	/usr/bin/dirname
ECHO?=		echo				# Shell builtin
ECHO_N?=	${ECHO} -n
EGREP?=		/usr/bin/egrep
EXPR?=		/bin/expr
FALSE?=		false				# Shell builtin
FILE_CMD?=	/usr/bin/file
FIND?=		/usr/bin/find
FGREP?=		/usr/bin/fgrep
GMAKE?=		/usr/bin/gnumake
GREP?=		/usr/bin/grep
GTAR?=		/usr/bin/gnutar	
GUNZIP_CMD?=	/usr/bin/gunzip -f
GZCAT?=		/usr/bin/gzcat
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
HEAD?=		/usr/bin/head
HOSTNAME_CMD?=	/bin/hostname
ID?=		/usr/bin/id
IMAKE?=		${X11BASE}/bin/imake ${IMAKEOPTS}
IMAKEOPTS+=	-DBuildHtmlManPages=NO
LDCONFIG?=	/sbin/ldconfig
LDD?=		/usr/bin/otool -L
LN?=		/bin/ln
LS?=		/bin/ls
M4?=		/usr/bin/m4 
MAIL_CMD?=	/usr/bin/mail
MKDIR?=		/bin/mkdir -p
MTREE?=		/usr/sbin/mtree
MV?=		/bin/mv
NICE?=		/usr/bin/nice
PATCH?=		/usr/bin/patch
.if exists(${LOCALBASE}/bin/pax)
PAX?=		${LOCALBASE}/bin/pax
.else
PAX?=		/bin/pax
.endif
PERL5?=		${LOCALBASE}/bin/perl
PKGLOCALEDIR?=	share
PS?=		/bin/ps
PWD_CMD?=	/bin/pwd	# needs to print physical path
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
# XXX: default from bsd.pkg.defaults.mk.  Verify/corerct for this platform
# and remove this comment.
RSH?=		/usr/bin/rsh
SED?=		/usr/bin/sed
SETENV?=	/usr/bin/env
SH?=		/bin/sh
SHLOCK=		/usr/bin/shlock
SORT?=		/usr/bin/sort
SU?=		/usr/bin/su
TAIL?=		/usr/bin/tail
.if exists(${LOCALBASE}/bin/tar)
TAR?=		${LOCALBASE}/bin/tar
.else
TAR?=		/usr/bin/tar
.endif
TEE?=		/usr/bin/tee
TEST?=		test				# Shell builtin
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		true				# Shell builtin
TSORT?=		/usr/bin/tsort
TYPE?=		type				# Shell builtin
WC?=		/usr/bin/wc
XARGS?=		/usr/bin/xargs

.if !defined(PKGSRC_COMPILER) || !empty(PKGSRC_COMPILER:Mgcc)
CPP_PRECOMP_FLAGS?=	-no-cpp-precomp	# use the GNU cpp, not the OS X cpp
.endif
DEF_UMASK?=		0022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
NOLOGIN?=		${FALSE}
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
_PKG_USER_SHELL?=	/usr/bin/false	# to match other system accounts
_USER_DEPENDS=		user>=20040801:../../sysutils/user_darwin

# imake installs manpages in weird places
# these values from /usr/X11R6/lib/X11/config/Imake.tmpl
IMAKE_MAN_SOURCE_PATH=	man/man
IMAKE_MAN_SUFFIX=	1
IMAKE_LIBMAN_SUFFIX=	3
IMAKE_FILEMAN_SUFFIX=	5
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_MANNEWSUFFIX=	${IMAKE_MAN_SUFFIX}

_DO_SHLIB_CHECKS=	yes	# on installation, fixup PLIST for shared libs
_IMAKE_MAKE=		${MAKE}	# program which gets invoked by imake
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
_PREFORMATTED_MAN_DIR=	cat	# directory where catman pages are
_USE_GNU_GETTEXT=	no	# Don't use GNU gettext
_USE_RPATH=		no	# don't add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-Wl,-x} # cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

LOCALBASE?=		${DESTDIR}/usr/pkg

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
# (it defaults to 'no' as per bsd.pkg.defaults.mk).
# Set the group and mode to meaningful values in that case (defaults to
# BINOWN, BINGRP and BINMODE as per bsd.pkg.defaults.mk).
# FIXME: Adjust to work on this system and enable the lines below.
#.if !(empty(SETGIDGAME:M[yY][eE][sS]))
#GAMEOWN=		games
#GAMEGRP=		games
#GAMEMODE=		2555
#.endif
