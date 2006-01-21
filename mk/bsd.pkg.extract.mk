# $NetBSD: bsd.pkg.extract.mk,v 1.19 2006/01/21 21:32:51 jlam Exp $
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
#	an archive named by the variable ${DOWNLOADED_DISTFILE} to the
#	current working directory.  The default is ${EXTRACT_CMD_DEFAULT}.
#
#    EXTRACT_CMD_DEFAULT uses the "extract" script to unpack archives.  The
#	precise manner in which extraction occurs may be tweaked by setting
#	EXTRACT_OPTS, EXTRACT_USING and EXTRACT_ELEMENTS.
#
#    EXTRACT_OPTS is a list of options to pass to the "extract" script
#	when using EXTRACT_CMD_DEFAULT.  See the comments at the head of
#	the "extract" script for a definitive list of the available
#	options.  The default list is empty.
#
#    EXTRACT_USING specifies the tool used to extract tar/ustar-format
#	archives when using EXTRACT_CMD_DEFAULT.  The possible values are
#	"gtar", "nbtar", and "pax".  By default, we use the "nbtar" tool
#	(pkgsrc's pax-as-tar).
#
#    EXTRACT_ELEMENTS is a list of files within the distfile to extract
#	when using EXTRACT_CMD_DEFAULT.  By default, this is empty, which
#	causes all files within the archive to be extracted.
#
# The following are read-only variables that may be used within a package
#	Makefile:
#
#    DOWNLOADED_DISTFILE represents the path to the distfile that is
#	currently being extracted, and may be used in custom EXTRACT_CMD
#	overrides, e.g.
#
#	    EXTRACT_CMD= ${TAIL} +25 ${DOWNLOADED_DISTFILE} > foo.pl
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
EXTRACT_ELEMENTS?=	# empty

###
### Discover which tools we need based on the file extensions of the
### distfiles.
###
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

###
### Build the default extraction command
###
_EXTRACT_ENV+=	${EXTRACT_OPTS_BIN:D	EXTRACT_OPTS_BIN=${EXTRACT_OPTS_BIN:Q}}
_EXTRACT_ENV+=	${EXTRACT_OPTS_LHA:D	EXTRACT_OPTS_LHA=${EXTRACT_OPTS_LHA:Q}}
_EXTRACT_ENV+=	${EXTRACT_OPTS_PAX:D	EXTRACT_OPTS_PAX=${EXTRACT_OPTS_PAX:Q}}
_EXTRACT_ENV+=	${EXTRACT_OPTS_RAR:D	EXTRACT_OPTS_RAR=${EXTRACT_OPTS_RAR:Q}}
_EXTRACT_ENV+=	${EXTRACT_OPTS_TAR:D	EXTRACT_OPTS_TAR=${EXTRACT_OPTS_TAR:Q}}
_EXTRACT_ENV+=	${EXTRACT_OPTS_ZIP:D	EXTRACT_OPTS_ZIP=${EXTRACT_OPTS_ZIP:Q}}
_EXTRACT_ENV+=	${EXTRACT_OPTS_ZOO:D	EXTRACT_OPTS_ZOO=${EXTRACT_OPTS_ZOO:Q}}
_EXTRACT_ENV+=	${TOOLS_BZCAT:D		BZCAT=${TOOLS_BZCAT:Q}}
_EXTRACT_ENV+=	${TOOLS_CAT:D		CAT=${TOOLS_CAT:Q}}
_EXTRACT_ENV+=	${TOOLS_CP:D		CP=${TOOLS_CP:Q}}
_EXTRACT_ENV+=	${TOOLS_ECHO:D		ECHO=${TOOLS_ECHO:Q}}
_EXTRACT_ENV+=	${TOOLS_GZCAT:D		GZCAT=${TOOLS_GZCAT:Q}}
_EXTRACT_ENV+=	${TOOLS_LHA:D		LHA=${TOOLS_LHA:Q}}
_EXTRACT_ENV+=	${TOOLS_MKDIR:D		MKDIR=${TOOLS_MKDIR:Q}}
_EXTRACT_ENV+=	${TOOLS_RM:D		RM=${TOOLS_RM:Q}}
_EXTRACT_ENV+=	${TOOLS_PAX:D		PAX=${TOOLS_PAX:Q}}
_EXTRACT_ENV+=	${TOOLS_SH:D		SH=${TOOLS_SH:Q}}
_EXTRACT_ENV+=	${TOOLS_TAR:D		TAR=${TOOLS_TAR:Q}}
_EXTRACT_ENV+=	${TOOLS_TEST:D		TEST=${TOOLS_TEST:Q}}
_EXTRACT_ENV+=	${TOOLS_UNRAR:D		UNRAR=${TOOLS_UNRAR:Q}}
_EXTRACT_ENV+=	${TOOLS_UNZIP_CMD:D	UNZIP_CMD=${TOOLS_UNZIP_CMD:Q}}
_EXTRACT_ENV+=	${TOOLS_UNZOO:D		UNZOO=${TOOLS_UNZOO:Q}}
_EXTRACT_ENV+=	${EXTRACT_ENV}

.if !empty(EXTRACT_USING:Mgtar)
EXTRACT_OPTS+=	${TOOLS_GTAR:D	-t ${TOOLS_GTAR}}
.elif !empty(EXTRACT_USING:Mnbtar)
EXTRACT_OPTS+=	${TOOLS_TAR:D	-t ${TOOLS_TAR}}
.else
EXTRACT_OPTS+=	${TOOLS_PAX:D	-t ${TOOLS_PAX}}
.endif

EXTRACT_CMD_DEFAULT=							\
	${SETENV} ${_EXTRACT_ENV}					\
	${.CURDIR}/../../mk/scripts/extract				\
		${EXTRACT_OPTS}						\
		${DOWNLOADED_DISTFILE} ${EXTRACT_ELEMENTS}

EXTRACT_CMD?=	${EXTRACT_CMD_DEFAULT}

DOWNLOADED_DISTFILE=	$${extract_file}

.PHONY: do-extract
.if !target(do-extract)
do-extract: ${WRKDIR}
.  for __file__ in ${EXTRACT_ONLY}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extract_file=${_DISTDIR:Q}/${__file__:Q}; export extract_file;	\
	cd ${WRKDIR} && ${EXTRACT_CMD}
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
.if !empty(INTERACTIVE_STAGE:Mextract) && defined(BATCH)
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
