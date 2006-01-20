# $NetBSD: bsd.pkg.extract.mk,v 1.15 2006/01/20 23:41:30 jlam Exp $
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
#    EXTRACT_USING specifies the tool used to extract tar/ustar-format
#	archives.  The possible values are "gtar", "nbtar", and "pax".
#	By default, we use the "nbtar" tool (NetBSD's pax-as-tar).
#
#    EXTRACT_ELEMENTS is a list of files within the distfile to extract.
#	This variable only takes effect for distfiles that are tarballs.
#	By default, this is empty, which causes all files within the
#	tarball to be extracted.
#
# The following targets are defined by bsd.pkg.extract.mk:
#
#    extract is the target that is invoked by the user to perform
#	extraction.
#
#    do-extract is the target that causes the actual extraction of
#	the distfiles to occur during the "extract" phase.  This target
#	may be overridden in a package Makefile.
#
#    {pre,post}-extract are the targets that are invoked before and after
#	do-extract, and may be overridden in a package Makefile.
#

EXTRACT_ONLY?=		${DISTFILES}
EXTRACT_SUFX?=		.tar.gz
EXTRACT_USING?=		nbtar

_EXTRACT_SUFFIXES=	.tar.gz .tgz .tar.bz2 .tbz .tbz2 .tar.Z .tar _tar.gz
_EXTRACT_SUFFIXES+=	.shar.gz .shar.bz2 .shar.Z .shar
_EXTRACT_SUFFIXES+=	.zip
_EXTRACT_SUFFIXES+=	.lha .lzh
_EXTRACT_SUFFIXES+=	.Z .bz2 .gz
_EXTRACT_SUFFIXES+=	.zoo
_EXTRACT_SUFFIXES+=	.bin
_EXTRACT_SUFFIXES+=	.rar

_EXTRACT_PATTERNS=	${EXTRACT_ONLY} ${EXTRACT_SUFX}

.if !empty(_EXTRACT_PATTERNS:M*.tar) || \
    !empty(_EXTRACT_PATTERNS:M*.tar.*) || \
    !empty(_EXTRACT_PATTERNS:M*.tbz) || \
    !empty(_EXTRACT_PATTERNS:M*.tbz2) || \
    !empty(_EXTRACT_PATTERNS:M*.tgz) || \
    !empty(_EXTRACT_PATTERNS:M*_tar.gz)

.  if !empty(EXTRACT_USING:Mgtar)
USE_TOOLS+=	gtar
.  elif !empty(EXTRACT_USING:Mnbtar)
USE_TOOLS+=	tar
.  else
USE_TOOLS+=	pax
.  endif
.endif
.if !empty(_EXTRACT_PATTERNS:M*.bz2) || \
    !empty(_EXTRACT_PATTERNS:M*.tbz) || \
    !empty(_EXTRACT_PATTERNS:M*.tbz2)
USE_TOOLS+=	bzcat
.endif
.if !empty(_EXTRACT_PATTERNS:M*.zip)
USE_TOOLS+=	unzip
.endif
.if !empty(_EXTRACT_PATTERNS:M*.lzh) || \
    !empty(_EXTRACT_PATTERNS:M*.lha)
USE_TOOLS+=	lha
.endif
.if !empty(_EXTRACT_PATTERNS:M*.gz) || \
    !empty(_EXTRACT_PATTERNS:M*.tgz) || \
    !empty(_EXTRACT_PATTERNS:M*.Z)
USE_TOOLS+=	gzcat
.endif
.if !empty(_EXTRACT_PATTERNS:M*.zoo)
USE_TOOLS+=	unzoo
.endif
.if !empty(_EXTRACT_PATTERNS:M*.rar)
USE_TOOLS+=	unrar
.endif

DECOMPRESS_CMD.tar.gz?=		${GZCAT}
DECOMPRESS_CMD.tgz?=		${DECOMPRESS_CMD.tar.gz}
DECOMPRESS_CMD.tar.bz2?=	${BZCAT}
DECOMPRESS_CMD.tbz?=		${DECOMPRESS_CMD.tar.bz2}
DECOMPRESS_CMD.tbz2?=		${DECOMPRESS_CMD.tar.bz2}
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

EXTRACT_CMD.zip?=	${UNZIP} ${EXTRACT_OPTS_ZIP} $${extract_file}
EXTRACT_OPTS_ZIP?=	-Laqo
EXTRACT_CMD.lha?=	${LHA} ${EXTRACT_OPTS_LHA} $${extract_file}
EXTRACT_OPTS_LHA?=	xq
EXTRACT_CMD.lzh?=	${EXTRACT_CMD.lha}
EXTRACT_CMD.zoo?=	${UNZOO} ${EXTRACT_OPTS_ZOO} $${extract_file}
EXTRACT_OPTS_ZOO?=	-x
EXTRACT_CMD.rar?=	${UNRAR} ${EXTRACT_OPTS_RAR} $${extract_file}
EXTRACT_OPTS_RAR?=	x -inul
EXTRACT_ENV.bin?=	# empty
EXTRACT_CMD.bin?=	${ECHO} yes | ${SETENV} ${EXTRACT_ENV.bin} $${extract_file} ${EXTRACT_OPTS_BIN} >/dev/null

.for __suffix__ in .gz .bz2 .Z
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} > `${BASENAME} $${extract_file} ${__suffix__}`
.endfor

.for __suffix__ in .shar.gz .shar.bz2 .shar.Z .shar
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} | ${SH}
.endfor

.if !empty(EXTRACT_USING:Mgtar)
_DFLT_EXTRACT_CMD?=	${DECOMPRESS_CMD} $${extract_file} | ${GTAR} -xf - ${EXTRACT_ELEMENTS}
.elif !empty(EXTRACT_USING:Mnbtar)
_DFLT_EXTRACT_CMD?=	${DECOMPRESS_CMD} $${extract_file} | ${TAR} -xf - ${EXTRACT_ELEMENTS}
.else
_DFLT_EXTRACT_CMD?=	${DECOMPRESS_CMD} $${extract_file} | ${PAX} -O -r ${EXTRACT_ELEMENTS}
.endif

.for __suffix__ in ${_EXTRACT_SUFFIXES}
.  if !defined(EXTRACT_CMD${__suffix__})
.    if !empty(EXTRACT_USING:Mgtar)
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} | ${GTAR} ${EXTRACT_OPTS_TAR} -xf - ${EXTRACT_ELEMENTS}
.    elif !empty(EXTRACT_USING:Mnbtar)
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} | ${TAR} ${EXTRACT_OPTS_TAR} -xf - ${EXTRACT_ELEMENTS}
.    else
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} | ${PAX} ${EXTRACT_OPTS_PAX} -O -r ${EXTRACT_ELEMENTS}
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

_EXTRACT_COOKIE=	${WRKDIR}/.extract_done

_EXTRACT_TARGETS+=	checksum
_EXTRACT_TARGETS+=	${WRKDIR}
_EXTRACT_TARGETS+=	${PKG_DB_TMPDIR}
_EXTRACT_TARGETS+=	acquire-extract-lock
_EXTRACT_TARGETS+=	${_EXTRACT_COOKIE}
_EXTRACT_TARGETS+=	release-extract-lock

.ORDER: ${_EXTRACT_TARGETS}

.PHONY: extract
extract: ${_EXTRACT_TARGETS}

.PHONY: acquire-extract-lock release-extract-lock
acquire-extract-lock:
	${_ACQUIRE_LOCK}
release-extract-lock:
	${_RELEASE_LOCK}

${_EXTRACT_COOKIE}:
.if ${INTERACTIVE_STAGE:Mextract} == "extract" && defined(BATCH)
	@${ECHO} "*** The extract stage of this package requires user interaction"
	@${ECHO} "*** Please extract manually with \"cd ${PKGDIR} && ${MAKE} extract\""
	@${TOUCH} ${_INTERACTIVE_COOKIE}
	@${FALSE}
.else
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} real-extract DEPENDS_TARGET=${DEPENDS_TARGET:Q} PKG_PHASE=extract
.endif

_REAL_EXTRACT_TARGETS+=	extract-message
_REAL_EXTRACT_TARGETS+=	extract-vars
_REAL_EXTRACT_TARGETS+=	install-depends
_REAL_EXTRACT_TARGETS+=	pre-extract
_REAL_EXTRACT_TARGETS+=	do-extract
_REAL_EXTRACT_TARGETS+=	post-extract
_REAL_EXTRACT_TARGETS+=	extract-cookie

.ORDER: ${_REAL_EXTRACT_TARGETS}

.PHONY: extract-message
extract-message:
	@${ECHO_MSG} "${_PKGSRC_IN}> Extracting for ${PKGNAME}"

.PHONY: extract-cookie
extract-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${PKGNAME} >> ${_EXTRACT_COOKIE}

.PHONY: real-extract
real-extract: ${_REAL_EXTRACT_TARGETS}

.PHONY: pre-extract post-extract
.if !target(pre-extract)
pre-extract:
	@${DO_NADA}
.endif
.if !target(post-extract)
post-extract:
	@${DO_NADA}
.endif
