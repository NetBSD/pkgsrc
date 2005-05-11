# $NetBSD: bsd.pkg.extract.mk,v 1.1 2005/05/11 04:01:49 jlam Exp $
#
# This Makefile fragment is included to bsd.pkg.mk and defines the
# relevant variables and targets for the "extract" phase.
#
# The following variables may be set by the package Makefile and
# specify how extraction happens:
#
#    EXTRACT_ONLY is a list of distfiles relative to ${_DISTDIR} to
#	extract and defaults to ${DISTFILES}.
#
#    EXTRACT_SUFX is the suffix for the default distfile to be
#	extracted.  The default suffix is ".tar.gz".
#
#    EXTRACT_CMD is a shell command list that extracts the contents of
#	an archive named by the shell variable "extract_file" based on
#	the extension of the archive.  The extensions understood by
#	EXTRACT_CMD are listed in _EXTRACT_SUFFIXES.
#
#    EXTRACT_CMD.<sufx> is a shell command list that extracts the
#	contents of an archive named by the shell variable "extract_file"
#	that ends in <sufx>.
#
#    EXTRACT_ELEMENTS is a list of files within the distfile to extract.
#	This variable only takes effect for distfiles that are tarballs.
#	By default, this is empty, which causes all files within the
#	tarball to be extracted.
#
# The following targets are defined by bsd.pkg.extract.mk:
#
#    do-extract is the target that causes the actual extraction of
#	the distfiles to occur during the "extract" phase.
#

EXTRACT_ONLY?=		${DISTFILES}
EXTRACT_SUFX?=		.tar.gz

_EXTRACT_SUFFIXES=	.tar.gz .tgz .tar.bz2 .tbz .tar.Z .tar _tar.gz
_EXTRACT_SUFFIXES+=	.shar.gz .shar.bz2 .shar.Z .shar
_EXTRACT_SUFFIXES+=	.zip
_EXTRACT_SUFFIXES+=	.lha .lzh
_EXTRACT_SUFFIXES+=	.Z .bz2 .gz
_EXTRACT_SUFFIXES+=	.zoo
_EXTRACT_SUFFIXES+=	.bin
_EXTRACT_SUFFIXES+=	.rar

# If the distfile has a tar.bz2 suffix, use bzcat in preference to gzcat,
# pulling in the "bzip2" package if necessary.  [Note: this is only for
# the benefit of pre-1.5 NetBSD systems. "gzcat" on newer systems happily
# decodes bzip2.]  Do likewise for ".zip" and ".lha" distfiles.
#
.if !empty(EXTRACT_ONLY:M*.bz2) || !empty(EXTRACT_ONLY:M*.tbz) || \
    !empty(EXTRACT_SUFX:M*.bz2) || !empty(EXTRACT_SUFX:M*.tbz)
.  if !empty(_USE_NEW_TOOLS:M[yY][eE][sS])
PKGSRC_USE_TOOLS+=	bzcat
.  elif exists(/usr/bin/bzcat)
BZCAT=			/usr/bin/bzcat <
.  else
BUILD_DEPENDS+=		bzip2>=0.9.0b:../../archivers/bzip2
BZCAT=			${LOCALBASE}/bin/bzcat
.  endif
.endif
.if !empty(EXTRACT_ONLY:M*.zip) || !empty(EXTRACT_SUFX:M*.zip)
BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
.endif
.if !empty(EXTRACT_ONLY:M*.lzh) || !empty(EXTRACT_ONLY:M*.lha) || \
    !empty(EXTRACT_SUFX:M*.lzh) || !empty(EXTRACT_SUFX:M*.lha)
BUILD_DEPENDS+=		lha>=114.9:../../archivers/lha
.endif
.if !empty(EXTRACT_ONLY:M*.gz) || !empty(EXTRACT_ONLY:M*.tgz) || \
    !empty(EXTRACT_SUFX:M*.gz) || !empty(EXTRACT_SUFX:M*.tgz)
.  if !empty(_USE_NEW_TOOLS:M[yY][eE][sS])
PKGSRC_USE_TOOLS+=	gzcat
.  elif !defined(GZCAT)
BUILD_DEPENDS+=         gzip-base>=1.2.4b:../../archivers/gzip-base
GZCAT=                  ${LOCALBASE}/bin/zcat
.  endif
.endif
.if !empty(EXTRACT_ONLY:M*.zoo) || !empty(EXTRACT_SUFX:M*.zoo)
BUILD_DEPENDS+=		unzoo-[0-9]*:../../archivers/unzoo
.endif
.if !empty(EXTRACT_ONLY:M*.rar) || !empty(EXTRACT_SUFX:M*.rar)
BUILD_DEPENDS+=		unrar>=3.3.4:../../archivers/unrar
.endif

DECOMPRESS_CMD.tar.gz?=		${GZCAT}
DECOMPRESS_CMD.tgz?=		${DECOMPRESS_CMD.tar.gz}
DECOMPRESS_CMD.tar.bz2?=	${BZCAT}
DECOMPRESS_CMD.tbz?=		${DECOMPRESS_CMD.tar.bz2}
DECOMPRESS_CMD.tar.Z?=		${GZCAT}
DECOMPRESS_CMD.tar?=		${CAT}

DECOMPRESS_CMD.shar.gz?=	${GZCAT}
DECOMPRESS_CMD.shar.bz2?=	${BZCAT}
DECOMPRESS_CMD.shar.Z?=		${GZCAT}
DECOMPRESS_CMD.shar?=		${CAT}

DECOMPRESS_CMD.Z?=		${GZCAT}
DECOMPRESS_CMD.bz2?=		${BZCAT}
DECOMPRESS_CMD.gz?=		${GZCAT}

DECOMPRESS_CMD?=		${GZCAT}
.for __suffix__ in ${_EXTRACT_SUFFIXES}
.  if !defined(DECOMPRESS_CMD${__suffix__})
DECOMPRESS_CMD${__suffix__}?=	${DECOMPRESS_CMD}
.  endif
.endfor

# If this is empty, then everything gets extracted.
EXTRACT_ELEMENTS?=	# empty

DOWNLOADED_DISTFILE=	$${extract_file}

EXTRACT_CMD.zip?=	${LOCALBASE}/bin/unzip ${EXTRACT_CMD_OPTS.zip} $${extract_file}
EXTRACT_CMD_OPTS.zip?=	-Laqo
EXTRACT_CMD.lha?=	${LOCALBASE}/bin/lha ${EXTRACT_CMD_OPTS.lha} $${extract_file}
EXTRACT_CMD_OPTS.lha?=	xq
EXTRACT_CMD.lzh?=	${EXTRACT_CMD.lha}
EXTRACT_CMD_OPTS.lzh?=	${EXTRACT_CMD_OPTS.lha}
EXTRACT_CMD.zoo?=	${LOCALBASE}/bin/unzoo ${EXTRACT_CMD_OPTS.zoo} $${extract_file}
EXTRACT_CMD_OPTS.zoo?=	-x
EXTRACT_CMD.rar?=	${LOCALBASE}/bin/unrar ${EXTRACT_CMD_OPTS.rar} $${extract_file}
EXTRACT_CMD_OPTS.rar?=	x -inul
EXTRACT_ENV.bin?=	# empty
EXTRACT_CMD.bin?=	${ECHO} yes | ${SETENV} ${EXTRACT_ENV.bin} $${extract_file} ${EXTRACT_CMD_OPTS.bin} >/dev/null

.for __suffix__ in .gz .bz2 .Z
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} > `${BASENAME} $${extract_file} ${__suffix__}`
.endfor

.for __suffix__ in .shar.gz .shar.bz2 .shar.Z .shar
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} | ${SH}
.endfor

# If EXTRACT_USING_PAX is defined, use pax in preference to (GNU) tar.
#
.if defined(EXTRACT_USING_PAX)
_DFLT_EXTRACT_CMD?=	${DECOMPRESS_CMD} $${extract_file} | ${PAX} -O -r ${EXTRACT_ELEMENTS}
.else
_DFLT_EXTRACT_CMD?=	${DECOMPRESS_CMD} $${extract_file} | ${GTAR} -xf - ${EXTRACT_ELEMENTS}
.endif

.for __suffix__ in ${_EXTRACT_SUFFIXES}
.  if !defined(EXTRACT_CMD${__suffix__})
.    if defined(EXTRACT_USING_PAX)
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} | ${PAX} -O -r ${EXTRACT_ELEMENTS}
.  else
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} | ${GTAR} -xf - ${EXTRACT_ELEMENTS}
.    endif
.  endif
.endfor

# _SHELL_EXTRACT is a "subroutine" for extracting an archive.  It extracts
# the contents of archive named by the shell variable "extract_file" based
# on the file extension of the archive.
#
_SHELL_EXTRACT=		case $${extract_file} in
.for __suffix__ in ${_EXTRACT_SUFFIXES}
_SHELL_EXTRACT+=	*${__suffix__})	${EXTRACT_CMD${__suffix__}} ;;
.endfor
_SHELL_EXTRACT+=	*)		${_DFLT_EXTRACT_CMD} ;;
_SHELL_EXTRACT+=	esac

EXTRACT_CMD?=		${_SHELL_EXTRACT}

.PHONY: do-extract
.if !target(do-extract)
do-extract: ${WRKDIR}
.  for __file__ in ${EXTRACT_ONLY}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extract_file="${_DISTDIR}/${__file__}";	export extract_file;	\
	cd ${WRKDIR}; ${EXTRACT_CMD}
.  endfor
.endif
