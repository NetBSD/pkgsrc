# $NetBSD: defs.SunOS.mk,v 1.66 2003/09/14 16:30:34 danw Exp $
#
# Variable definitions for the SunOS/Solaris operating system.

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
DC?=		/usr/bin/dc
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
GTAR?=		${ZOULARISBASE}/bin/tar
.endif
.if exists(${LOCALBASE}/bin/gzip)
GUNZIP_CMD?=	${LOCALBASE}/bin/gunzip -f
GZCAT?=		${LOCALBASE}/bin/zcat
GZIP?=		-9
GZIP_CMD?=	${LOCALBASE}/bin/gzip -nf ${GZIP}
.elif exists(/usr/bin/gzip)
GUNZIP_CMD?=	/usr/bin/gunzip -f
GZCAT?=		/usr/bin/gzcat
GZIP?=		-9
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
.endif
HEAD?=		/usr/bin/head
HOSTNAME_CMD?=	/bin/hostname
ID?=		/usr/xpg4/bin/id
IMAKE?=		${X11BASE}/bin/imake -DHasGcc2=YES -DHasGcc2ForCplusplus=YES
LDCONFIG?=	/usr/bin/true
LN?=		/usr/bin/ln
LS?=		/usr/bin/ls
M4?=		/usr/ccs/bin/m4
MKDIR?=		/usr/bin/mkdir -p
.if exists(${LOCALBASE}/sbin/mtree)
MTREE?=		${LOCALBASE}/sbin/mtree
.endif
MTREE?=		${ZOULARISBASE}/bin/mtree
MV?=		/usr/bin/mv
NICE?=		/usr/xpg4/bin/nice
.if exists(/usr/bin/gpatch)
PATCH?=		/usr/bin/gpatch -b
.elif exists(${LOCALBASE}/bin/gpatch)
PATCH?=		${LOCALBASE}/bin/gpatch -b
.else
PATCH?=		${LOCALBASE}/bin/patch -b
.endif
.if exists(${LOCALBASE}/bin/pax)
PAX?=		${LOCALBASE}/bin/pax
.else
PAX?=		/bin/pax
.endif
PERL5?=		${LOCALBASE}/bin/perl
PKGLOCALEDIR?=	lib
PS?=		/bin/ps
PWD_CMD?=	/bin/pwd	# needs to print physical path
RM?=		/usr/bin/rm
RMDIR?=		/usr/bin/rmdir
SED?=		/usr/xpg4/bin/sed
SETENV?=	/usr/bin/env
SH?=		/bin/ksh
SHLOCK=		${LOCALBASE}/bin/shlock
SORT?=		/usr/bin/sort
SU?=		/usr/bin/su
TAIL?=		/usr/xpg4/bin/tail
TEE?=		/usr/bin/tee
TEST?=		/usr/bin/test
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		/usr/bin/true
TSORT?=		/usr/ccs/bin/tsort
TYPE?=		/usr/bin/type
WC?=		/usr/bin/wc
XARGS?=		/usr/bin/xargs

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
GROUPADD?=		/usr/sbin/groupadd
MOTIF_TYPE_DEFAULT?=	dt		# default 2.0 compatible libs type
MOTIF12_TYPE_DEFAULT?=	dt		# default 1.2 compatible libs type
NOLOGIN?=		${FALSE}
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		root
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -v `ulimit -H -v`
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
_OPSYS_RPATH_NAME=	-R		# name of symbol in rpath directive to linker 
_PATCH_CAN_BACKUP=	yes		# native patch(1) can make backups
_PATCH_BACKUP_ARG= 	-V simple -z	# switch to patch(1) for backup suffix
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
_INCOMPAT_ICONV=       SunOS-*-*

.if !defined(DEBUG_FLAGS)
_STRIPFLAG_CC?=		-s	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	-s	# install(1) option to strip
.endif

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

LOCALBASE?=             ${DESTDIR}/usr/pkg
.if !defined(ZOULARISBASE)
.  if exists(${LOCALBASE}/bsd)
ZOULARISBASE:=		${LOCALBASE}/bsd
.  else
ZOULARISBASE:=		${LOCALBASE}
.  endif
.endif
.if exists(${LOCALBASE}/sbin/pkg_info)
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
.elif exists(${ZOULARISBASE}/sbin/pkg_info)
PKG_TOOLS_BIN?=		${ZOULARISBASE}/sbin
.endif
PKG_TOOLS_BIN?=		${ZOULARISBASE}/bin
