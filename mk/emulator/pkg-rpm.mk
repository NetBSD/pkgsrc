# $NetBSD: pkg-rpm.mk,v 1.7 2017/08/21 12:49:17 jlam Exp $
#
# RPM package format
#
# Package-settable variables:
#
# RPM2PKG_PLIST
#	This is the path to the PLIST created by rpm2pkg(8) which will
#	list the files and directories extracted from the RPMs.  If
#	this is empty, then no PLIST is created.
#
#	Default value: ${WRKDIR}/.PLIST.rpm2pkg
#
# RPM2PKG_PREFIX
#	This is the directory under which the contents of the RPMs will
#	be extracted.  This directory is stripped from the paths which
#	are stored in ${RPM2PKG_PLIST}.
#
#	Default value: ${WRKDIR}
#
# RPM2PKG_SUBPREFIX
#	This is the subdirectory under ${RPM2PKG_PREFIX} within which
#	the RPMs are directly extracted.  If this is empty, then the
#	RPMs are extracted directly into ${RPM2PKG_PREFIX}.
#
#	Default value: empty
#
# RPM2PKG_STRIP
#	This is the number of path components to strip from the head
#	of paths of files and directories stored in the RPMs during
#	extraction.  RPMs usually store all paths with a leading path
#	component of ``./''.
#
#	Default value: 1
#
# RPM2PKG_STAGE
#	Stage at which to run the ``extract-rpm'' target.
#
#	Default value: do-extract
#
# RPMFILES
#	The list of paths to RPMs to extract using rpm2pkg(8).
#
#	Default value: all *.rpm files in DISTFILES located in ${_DISTDIR}
#
# RPMIGNOREPATH
#	The list of files or paths to skip during extraction of the RPMs.
#
#	Default value: undefined
#
# Public targets:
#
# extract-rpm
#	Runs rpm2pkg(8) with the appropriate arguments based on the
#	RPM* variables set in the package Makefile to extract the
#	files listed in RPMFILES.
#

TOOL_DEPENDS+=		rpm2pkg>=3.1.4:../../pkgtools/rpm2pkg
RPM2PKG=		${LOCALBASE}/sbin/rpm2pkg

RPMFILES?=		${DISTFILES:M*.rpm:S/^/${_DISTDIR}\//}
BUILD_DEFS+=		RPMFILES
.if defined(RPMIGNOREPATH)
BUILD_DEFS+=		RPMIGNOREPATH
.endif

RPM2PKGSTRIP?=		${RPM2PKG_STRIP}

RPM2PKG_STRIP?=		1
RPM2PKG_PREFIX?=	${WRKDIR}
RPM2PKG_SUBPREFIX?=	# empty
RPM2PKG_PLIST?=		${WRKDIR}/.PLIST.rpm2pkg

# By default, extract the RPMs during the do-extract step.
RPM2PKG_STAGE?=		do-extract

RPM2PKG_ARGS_DFLT=	-d ${RPM2PKG_PREFIX:Q}
.if !empty(RPM2PKG_SUBPREFIX)
RPM2PKG_ARGS_DFLT+=	-p ${RPM2PKG_SUBPREFIX:Q}
.endif
.if !empty(RPM2PKG_PLIST)
RPM2PKG_ARGS_DFLT+=	-f ${RPM2PKG_PLIST:Q}
.endif
.if empty(RPM2PKG_STRIP:M0)
RPM2PKG_ARGS_DFLT+=	-s ${RPM2PKG_STRIP}
.endif
.for _ignoredir_ in ${RPMIGNOREPATH}
RPM2PKG_ARGS_DFLT+=	-i ${_ignoredir_}
.endfor
RPM2PKG_ARGS?=		${RPM2PKG_ARGS_DFLT}

PLIST_SRC_DFLT+=	${RPM2PKG_PLIST}

# We handle the extraction of the RPMs in the extract-rpm target below.
EXTRACT_ONLY?=		# empty

.PHONY: extract-rpm
extract-rpm:
	@${STEP_MSG} "Extracting RPM files"
.if !empty(RPM2PKG_PLIST)
	${RUN} ${RM} -f ${RPM2PKG_PLIST}
.endif
	${RUN} ${RPM2PKG} ${RPM2PKG_ARGS} ${RPMFILES}

${RPM2PKG_STAGE}: extract-rpm
