# $NetBSD: SunOS.mk,v 1.13 2005/05/03 19:35:24 jlam Exp $
#
# Variable definitions for the SunOS/Solaris operating system.

ECHO_N?=	${ECHO} -n
PKGLOCALEDIR?=	lib
PS?=		/bin/ps
# XXX: default from bsd.pkg.defaults.mk.  Verify/corerct for this platform
# and remove this comment.
RSH?=		/usr/bin/rsh
SU?=		/usr/bin/su
TYPE?=		/usr/bin/type

.if empty(_USE_NEW_TOOLS:M[yY][eE][sS])
AWK?=		/usr/bin/nawk
BASENAME?=	/usr/bin/basename
CAT?=		/usr/bin/cat
CHMOD?=		/usr/bin/chmod
CHOWN?=		/usr/bin/chown
CHGRP?=		/usr/bin/chgrp
CMP?=		cmp
CP?=		/usr/bin/cp
CUT?=		/usr/bin/cut
DATE?=		/usr/xpg4/bin/date
DIRNAME?=	/usr/bin/dirname
ECHO?=		/usr/ucb/echo
EGREP?=		/usr/xpg4/bin/grep -E
EXPR?=		/usr/xpg4/bin/expr
FALSE?=		/usr/bin/false
FGREP?=		/usr/xpg4/bin/fgrep
FILE_CMD?=	/usr/bin/file
FIND?=		/usr/bin/find
GMAKE?=		${LOCALBASE}/bin/gmake
GREP?=		/usr/xpg4/bin/grep
.if exists(${LOCALBASE}/bin/gtar)
GTAR?=		${LOCALBASE}/bin/gtar
.else
GTAR?=		${LOCALBASE}/bin/tar
.endif
.if exists(${LOCALBASE}/bin/gzip)
GUNZIP_CMD?=	${LOCALBASE}/bin/gunzip -f
GZCAT?=		${LOCALBASE}/bin/zcat
GZIP_CMD?=	${LOCALBASE}/bin/gzip -nf ${GZIP}
.elif exists(/usr/bin/gzip)
GUNZIP_CMD?=	/usr/bin/gzip -df
GZCAT?=		/usr/bin/gzip -cd
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
.endif
HEAD?=		/usr/bin/head
HOSTNAME_CMD?=	/bin/hostname
ID?=		/usr/xpg4/bin/id
IMAKE?=		${X11BASE}/bin/imake ${IMAKEOPTS}
LDCONFIG?=	/usr/bin/true
LN?=		/usr/bin/ln
LS?=		/usr/bin/ls
M4?=		/usr/ccs/bin/m4
MAIL_CMD?=	/usr/bin/mailx
MKDIR?=		/usr/bin/mkdir -p
MTREE?=		${LOCALBASE}/sbin/mtree
MV?=		/usr/bin/mv
NICE?=		/usr/xpg4/bin/nice
.if exists(/usr/bin/gpatch)
PATCH?=		/usr/bin/gpatch
.else
PATCH?=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}patch
.endif
PAX?=		${LOCALBASE}/bin/pax
PERL5?=		${LOCALBASE}/bin/perl
PWD_CMD?=	/bin/pwd	# needs to print physical path
RM?=		/usr/bin/rm
RMDIR?=		/usr/bin/rmdir
.if exists(${LOCALBASE}/bin/nbsed)
SED?=		${LOCALBASE}/bin/nbsed
.else
SED?=		/usr/xpg4/bin/sed
.endif
SETENV?=	/usr/bin/env
SH?=		/bin/ksh
SHLOCK=		${LOCALBASE}/bin/shlock
SORT?=		/usr/bin/sort
TAIL?=		/usr/xpg4/bin/tail
TAR?=		${LOCALBASE}/bin/tar
TEE?=		/usr/bin/tee
TEST?=		test
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		/usr/bin/true
TSORT?=		/usr/ccs/bin/tsort
WC?=		/usr/bin/wc
XARGS?=		/usr/bin/xargs
.endif

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
GROUPADD?=		/usr/sbin/groupadd
MOTIF_TYPE_DEFAULT?=	dt		# default 2.0 compatible libs type
NOLOGIN?=		${FALSE}
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		root
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `${SETENV} LC_MESSAGES=C ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `${SETENV} LC_MESSAGES=C ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -v `${SETENV} LC_MESSAGES=C ulimit -H -v`
USERADD?=		/usr/sbin/useradd

# imake installs manpages in weird places
IMAKE_MAN_SOURCE_PATH=	share/man/man
IMAKE_MAN_SUFFIX=	1
IMAKE_LIBMAN_SUFFIX=	3
IMAKE_FILEMAN_SUFFIX=	5
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_MANNEWSUFFIX=	${IMAKE_MAN_SUFFIX}

_DO_SHLIB_CHECKS=	yes		# fixup PLIST for shared libs
_IMAKE_MAKE=	/usr/ccs/bin/make	# program which gets invoked by imake
.if exists(/usr/include/netinet/ip6.h)
_OPSYS_HAS_INET6=	yes		# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no		# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no		# Java is not standard
_OPSYS_HAS_MANZ=	no		# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no		# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no		# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF		# shared lib type
_PATCH_CAN_BACKUP=	yes		# native patch(1) can make backups
_PATCH_BACKUP_ARG?= 	-b -V simple -z	# switch to patch(1) for backup suffix
_PREFORMATTED_MAN_DIR=	man		# directory where catman pages are
_USE_GNU_GETTEXT=	yes		# Use GNU gettext
_USE_RPATH=		yes		# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is the standard Solaris linker, /usr/ccs/bin/ld. The use of GNU
# ld is not currently supported.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-z allextract
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-z defaultextract

# Solaris has /usr/include/iconv.h, but it's not GNU iconv, so mark it
# incompatible.
_INCOMPAT_ICONV=	SunOS-*-*

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

# Migration aid for old /usr/local LOCALBASE
.if !defined(LOCALBASE) && exists(${DESTDIR}/usr/local/libexec/cgi-bin) && \
	!exists(${DESTDIR}/usr/pkg/libexec/cgi-bin)
.BEGIN:
	@echo "On Solaris and /usr/local/libexec/cgi-bin found:"
	@echo "- If you have an existing pkgsrc installation & wish to continue"
	@echo "  using /usr/local, append LOCALBASE=/usr/local to /etc/mk.conf."
	@echo "- Otherwise set LOCALBASE=/usr/pkg in your environment for the"
	@echo "  first package install."
	@false
.endif

.if !exists(${SED}) || ${SED} == "/usr/xpg4/bin/sed"
.BEGIN:
	@echo ""
	@echo "==========================================================================="
	@echo ""
	@echo "ERROR: pkgsrc now requires a more functional sed(1) than Solaris provides."
	@echo "you can satisfy this requirement by running:"
	@echo ""
	@echo "    cd ${PKGSRCDIR}/textproc/nbsed; ${MAKE} install"
	@echo ""
	@echo "this will install ${LOCALBASE}/bin/nbsed and eliminate this message."
	@echo "(nbsed is already installed by recent bootstrap-pkgsrc)."
	@echo ""
	@echo "==========================================================================="
	@echo ""
	@false
.endif

LOCALBASE?=		${DESTDIR}/usr/pkg

.if exists(${LOCALBASE}/sbin/pkg_info)
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
.else
PKG_TOOLS_BIN?=		${LOCALBASE}/bin
.endif

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
# FIXME: Adjust to work on this system and enable the lines below.
#_OPSYS_MAX_CMDLEN_CMD=	/sbin/sysctl -n kern.argmax

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
