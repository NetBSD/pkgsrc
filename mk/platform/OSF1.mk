# $NetBSD: OSF1.mk,v 1.4 2005/05/03 15:10:59 jlam Exp $
#
# Variable definitions for the OSF1 operating system.

# current bmake is broken, see pkg/25559

#.SHELL: name=ksh path=/bin/ksh hasErrCtl=true \
#	check="set -e" ignore="set +e" \
#	echo="set -v" quiet="set +v" filter="set +v" \
#	echoFlag=v errFlag=e

AWK?=		/usr/bin/awk
BASENAME?=	/usr/bin/basename
CAT?=		/bin/cat
CHMOD?=		/bin/chmod
CHOWN?=		/bin/chown
CHGRP?=		/usr/bin/chgrp
CMP?=		/usr/bin/cmp
CP?=		/bin/cp
CPP?=		/usr/bin/cpp
CUT?=		/usr/bin/cut
DATE?=		/bin/date
DIRNAME?=	/usr/bin/dirname
ECHO?=		/usr/bin/echo				
ECHO_N?=	${SETENV} CMD_ENV=bsd /usr/bin/echo -n
EGREP?=		/usr/bin/grep -E
EXPR?=		/bin/expr
FALSE?=		false				# Shell builtin
FETCH_CMD?= ${LOCALBASE}/bin/ftp
FGREP?=		/usr/bin/grep -F
FILE_CMD?=	/usr/bin/file
FIND?=		/usr/bin/find
GMAKE?=		${LOCALBASE}/bin/gmake
GREP?=		/usr/bin/grep
.if exists(${LOCALBASE}/bin/gtar)
GTAR?=		${LOCALBASE}/bin/gtar
.else
GTAR?=/usr/bin/tar
.endif
GUNZIP_CMD?=	/usr/bin/gunzip -f
GZCAT?=		/usr/bin/gzcat
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
HEAD?=		/usr/bin/head
HOSTNAME_CMD?=	/bin/hostname
ID?=		/usr/bin/id
INSTALL=	${LOCALBASE}/bin/install-sh
LDCONFIG?=	${TRUE}
LN?=		/bin/ln
LS?=		/bin/ls
M4?=		/usr/bin/m4
MAIL_CMD?=	/usr/bin/mailx
MKDIR?=		/bin/mkdir -p
MTREE?=		${LOCALBASE}/sbin/mtree
MV?=		/bin/mv
NICE?=		/usr/bin/nice
PATCH?=		${LOCALBASE}/bin/gpatch
PAX?=		${LOCALBASE}/bin/pax
.if exists(${LOCALBASE}/bin/perl)
PERL5?=		${LOCALBASE}/bin/perl
.else
PERL5?=		/usr/bin/perl
.endif
PKGLOCALEDIR=	share
PS?=		/bin/ps
PWD_CMD?=	/bin/pwd	# needs to print physical path
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
SED?=		${LOCALBASE}/bin/nbsed
SETENV?=	/usr/bin/env
SH?=		/bin/ksh			# recommendend on Tru64
#SHLOCK=	${LOCALBASE}/bin/shlock		# need to make this work
SORT?=		/usr/bin/sort
STRIP?=		/usr/bin/strip
SU?=		/usr/bin/su
TAIL?=		/usr/bin/tail
TAR?=		/usr/bin/tar
TEE?=		/usr/bin/tee
TEST?=		test				# Shell builtin
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		true				# Shell builtin
TSORT?=		/usr/bin/tsort
TYPE?=		type				# Shell builtin
WC?=		/usr/bin/wc
XARGS?=		/usr/bin/xargs

USERADD?=	/usr/sbin/useradd
GROUPADD?=	/usr/sbin/groupadd

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		0022
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-non_hidden	# add symbols to the dynamic symbol table
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
MOTIF12_TYPE_DEFAULT?=	lesstif12	# default 1.2 compatible libs type
NOLOGIN?=		/etc/nologin
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_USER?=		root
ROOT_GROUP?=		system
ULIMIT_CMD_datasize?=	echo ULIMIT_CMD_datasize_FIXME
ULIMIT_CMD_stacksize?=	echo ULIMIT_CMD_stacksize_FIXME
ULIMIT_CMD_memorysize?=	echo ULIMIT_CMD_memorysize_FIXME
# imake installs manpages in weird places
# these values from /usr/X11R6/lib/X11/config/NetBSD.cf
IMAKE_MAN_SOURCE_PATH=	man/cat
IMAKE_MAN_SUFFIX=	1
IMAKE_LIBMAN_SUFFIX=	3
IMAKE_FILEMAN_SUFFIX=	5
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_MANNEWSUFFIX=	1

_DO_SHLIB_CHECKS=	yes	# fixup PLIST
_IMAKE_MAKE=		${MAKE}	# program which gets invoked by imake
.if exists(/usr/include/netinet/ip6.h)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	yes	# Java is standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_RPATH_NAME=	-rpath,	# name of symbol in rpath directive to linker 
_OPSYS_SHLIB_TYPE=	COFF	# type of shared lib
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-b -V simple -z 	# switch to patch(1) for backup suffix
_PREFORMATTED_MAN_DIR=	cat	# directory where catman pages are
_USE_GNU_GETTEXT=	yes	# Don't use GNU gettext
_USE_RPATH=		yes	# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,-all
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,-none

DEFAULT_SERIAL_DEVICE?=	/dev/tty00
SERIAL_DEVICES?=	/dev/tty00 \
			/dev/tty01

_INCOMPAT_ICONV=   OSF1-*-*

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U}	# install(1) option to strip
