# $NetBSD: defs.UnixWare.mk,v 1.2 2004/04/19 20:19:46 jmmv Exp $
#
# Variable definitions for the UnixWare 7 operating system.

AWK?=		/usr/bin/nawk
BASENAME?=	/usr/bin/basename
CAT?=		/usr/bin/cat
CHMOD?=		/usr/bin/chmod
CHOWN?=		/usr/bin/chown
CHGRP?=		/usr/bin/chgrp
CMP?=		/usr/bin/cmp
CP?=		/usr/bin/cp
CUT?=		/usr/bin/cut
DATE?=		/usr/bin/date
DC?=		/usr/bin/dc
DIRNAME?=	/usr/bin/dirname
ECHO?=		/usr/ucb/echo
ECHO_N?=	${ECHO} -n
EGREP?=		/usr/bin/grep -E
EXPR?=		/usr/bin/expr
FALSE?=		/usr/bin/false
FGREP?=		/usr/bin/grep -F
FILE_CMD?=	/usr/bin/file
FIND?=		/usr/bin/find
GMAKE?=		${LOCALBASE}/bin/gmake
GREP?=		/usr/bin/grep
.if exists(${LOCALBASE}/bin/gtar)
GTAR?=		${LOCALBASE}/bin/gtar
.else
GTAR?=		${LOCALBASE}/bin/tar
.endif
.if exists(${LOCALBASE}/bin/gzip)
GUNZIP_CMD?=	${LOCALBASE}/bin/gunzip -f
GZCAT?=		${LOCALBASE}/bin/zcat
GZIP?=		-9
GZIP_CMD?=	${LOCALBASE}/bin/gzip -nf ${GZIP}
.elif exists(/usr/local/bin/gzip)
GUNZIP_CMD?=	/usr/local/bin/gzip -df
GZCAT?=		/usr/local/bin/gzip -cd
GZIP?=		-9
GZIP_CMD?=	/usr/local/bin/gzip -nf ${GZIP}
.endif
HEAD?=		/usr/bin/head
HOSTNAME_CMD?=	/usr/bin/hostname
ID?=		/usr/bin/id
IMAKE?=		# XXX only available in the SDK? what about xmkmf?
LDCONFIG?=	/usr/bin/true
LN?=		/usr/bin/ln
LS?=		/usr/bin/ls
M4?=		/usr/ccs/bin/m4
MAIL_CMD?=	/usr/bin/mailx
MKDIR?=		${LOCALBASE}/sbin/mkdir-sh -p
MTREE?=		${LOCALBASE}/sbin/mtree
MV?=		/usr/bin/mv
NICE?=		/usr/bin/nice
PATCH?=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}patch
PAX?=		${LOCALBASE}/bin/pax
PERL5?=		${LOCALBASE}/bin/perl
PKGLOCALEDIR?=	lib
PS?=		/usr/bin/ps
PWD_CMD?=	/usr/bin/pwd	# needs to print physical path
RM?=		/usr/bin/rm
RMDIR?=		/usr/bin/rmdir
.if exists(${LOCALBASE}/bin/nbsed)
SED?=		${LOCALBASE}/bin/nbsed
.else
SED?=		/usr/bin/sed
.endif
SETENV?=	/usr/bin/env
SH?=		/usr/bin/ksh
SHLOCK=		${LOCALBASE}/bin/shlock
SORT?=		/usr/bin/sort
SU?=		/usr/bin/su
TAIL?=		/usr/bin/tail
TAR?=		${LOCALBASE}/bin/tar
TEE?=		/usr/bin/tee
TEST?=		test				# Shell builtin
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
.if exists(/usr/include/netinet/in6.h)
_OPSYS_HAS_INET6=	yes		# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no		# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no		# Java is not standard
_OPSYS_HAS_MANZ=	no		# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no		# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no		# -lpthread needed for pthreads
# XXX native linker for UnixWare doesn't have this, see also _USE_RPATH
_OPSYS_RPATH_NAME=			# name of symbol in rpath directive to linker
_OPSYS_SHLIB_TYPE=	ELF/a.out	# shared lib type
_PATCH_CAN_BACKUP=	yes		# native patch(1) can make backups
_PATCH_BACKUP_ARG?= 	-b -V simple -z	# switch to patch(1) for backup suffix
_PREFORMATTED_MAN_DIR=	man		# directory where catman pages are
_USE_GNU_GETTEXT=	yes		# Use GNU gettext
_USE_RPATH=		no		# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is the standard Solaris linker, /usr/ccs/bin/ld. The use of GNU
# ld is not currently supported.
# XXX is this needed for UnixWare?
_OPSYS_WHOLE_ARCHIVE_FLAG=
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=

# UnixWare has /usr/include/iconv.h, but it's not GNU iconv, so mark it
# incompatible.
_INCOMPAT_ICONV=	UnixWare-*-*

# XXX Where are those variables used?
.if !defined(DEBUG_FLAGS)
_STRIPFLAG_CC?=			# cc(1) option to strip
_STRIPFLAG_INSTALL?=		# install(1) option to strip
.endif

LOCALBASE?=		${DESTDIR}/usr/pkg

PKG_TOOLS_BIN?=		${LOCALBASE}/sbin

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
# FIXME: Adjust to work on this system and enable the lines below.
#.if defined(GNU_CONFIGURE) && defined(USE_LIBTOOL)
#_OPSYS_MAX_CMDLEN!=	/sbin/sysctl -n kern.argmax
#CONFIGURE_ENV+=		lt_cv_sys_max_cmd_len=${_OPSYS_MAX_CMDLEN}
#.endif
