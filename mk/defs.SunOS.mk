# $NetBSD: defs.SunOS.mk,v 1.19 2001/12/19 10:29:11 agc Exp $
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
DC?=		/usr/bin/dc
DIRNAME?=	/usr/bin/dirname
ECHO?=		/usr/ucb/echo
EGREP?=		/usr/xpg4/bin/egrep
FALSE?=		/usr/bin/false
FILE_CMD?=	/usr/bin/file
FIND?=		/usr/bin/find
GMAKE?=		${LOCALBASE}/bin/gmake
GREP?=		/usr/bin/grep
GTAR?=		${ZOULARISBASE}/bin/tar
.if exists(/usr/bin/gzip)
GUNZIP_CMD?=	/usr/bin/gunzip -f
GZCAT?=		/usr/bin/gzcat
GZIP?=		-9
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
.else
GUNZIP_CMD?=	${LOCALBASE}/bin/gunzip -f
GZCAT?=		${LOCALBASE}/bin/zcat
GZIP?=		-9
GZIP_CMD?=	${LOCALBASE}/bin/gzip -nf ${GZIP}
.endif
HEAD?=		/usr/bin/head
ID?=		/usr/xpg4/bin/id
LDCONFIG?=	/usr/bin/true
LN?=		/usr/bin/ln
LS?=		/usr/bin/ls
MKDIR?=		/usr/bin/mkdir -p
MTREE?=		${ZOULARISBASE}/bin/mtree
MV?=		/usr/bin/mv
.if exists(/usr/bin/gpatch)
PATCH?=		/usr/bin/gpatch -b
.else
PATCH?=		${LOCALBASE}/bin/patch -b
.endif
PAX?=		/bin/pax
PKGLOCALEDIR?=	lib
RM?=		/usr/bin/rm
RMDIR?=		/usr/bin/rmdir
SED?=		/usr/xpg4/bin/sed
SETENV?=	/usr/bin/env
SH?=		/bin/ksh
SORT?=		/usr/bin/sort
SU?=		/usr/bin/su
TAIL?=		/usr/xpg4/bin/tail
TEST?=		/usr/bin/test
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		/usr/bin/true
TYPE?=		/usr/bin/type
WC?=		/usr/bin/wc
XARGS?=		/usr/bin/xargs

DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
GROUPADD?=		/usr/sbin/groupadd
MOTIF_TYPE_DEFAULT?=	dt		# default 2.0 compatible libs type
MOTIF12_TYPE_DEFAULT?=	dt		# default 1.2 compatible libs type
NOLOGIN?=		${FALSE}
ROOT_GROUP?=		root
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
USERADD?=		/usr/sbin/useradd

_DO_LIBINTL_CHECKS=	yes		# perform checks for valid libintl
_DO_SHLIB_CHECKS=	yes		# fixup PLIST for shared libs
_IMAKE_MAKE=	/usr/ccs/bin/make	# program which gets invoked by imake
_OPSYS_HAS_GMAKE=	no		# GNU make is not standard
_OPSYS_HAS_MANZ=	no		# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no		# libossaudio is available
_PATCH_BACKUP_ARG= 	-z		# switch to patch(1) for backup file
_PREFORMATTED_MAN_DIR=	man		# directory where catman pages are
_USE_RPATH=		yes		# add rpath to LDFLAGS

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
PKG_TOOLS_BIN?=		${ZOULARISBASE}/bin

.if ${X11BASE} == "/usr/openwin"
HAVE_OPENWINDOWS=	YES
.endif

