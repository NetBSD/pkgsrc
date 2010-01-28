# $NetBSD: module.mk,v 1.9 2010/01/28 22:37:32 minskim Exp $
#
# This Makefile fragment is inteded to be included by packages that build
# TeX Live 2008 packages.
#
# Package-settable variables:
#
# TEX_FORMAT_NAMES
#	See ../../print/texlive-tetex/format.mk.
#
# TEX_HYPHEN_DAT
#	See ../../print/texlive-tetex/hyphen.mk.
#
# TEX_HYPHEN_DEF
#	See ../../print/texlive-tetex/hyphen.mk.
#
# TEX_MAP_FILES
#	See ../../print/texlive-tetex/map.mk.
#
# TEX_MIXEDMAP_FILES
#	See ../../print/texlive-tetex/map.mk.
#
# TEX_TEXMF_DIRS
#	See ../../print/kpathsea/texmf.mk.
#
# TEXLIVE_IGNORE_PATTERNS
#	glob patterns for files and directories in ${WRKSRC} that
#	should not be installed.

CATEGORIES?=	print
MASTER_SITES?=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/2008/archive/}
DIST_SUBDIR?=	${PKGNAME_NOREV}
EXTRACT_SUFX?=	.tar.lzma

HOMEPAGE?=	http://www.tug.org/texlive/

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_BUILD?=	yes
WRKSRC?=	${WRKDIR}

.PHONY: _texlive-set-permission _texlive-man _texlive-install
_texlive-set-permission:
.for _pat in ${TEXLIVE_IGNORE_PATTERNS}
	${RM} -rf ${WRKSRC}/${_pat}
.endfor
.for _texmf in texmf texmf-dist texmf-doc
	if [ -d ${WRKSRC}/${_texmf} ]; then \
	  ${FIND} ${WRKSRC}/${_texmf} -type d -exec ${CHMOD} ${PKGDIRMODE} {} \; ; \
	  ${FIND} ${WRKSRC}/${_texmf} -type f -exec ${CHMOD} ${SHAREMODE} {} \; ; \
	fi
.endfor

_texlive-man:
	if [ -d ${WRKSRC}/texmf/doc/man ]; then \
		${MKDIR} ${WRKSRC}/man; \
		${MV} ${WRKSRC}/texmf/doc/man/* ${WRKSRC}/man; \
		${FIND} ${WRKSRC}/man -name \*.pdf -exec ${RM} {} \; ; \
		${RMDIR} -p ${WRKSRC}/texmf/doc/man || ${TRUE}; \
	fi

_texlive-install:
.for _texmf in texmf texmf-dist
	if [ -d ${WRKSRC}/${_texmf} ]; then \
		cd ${WRKSRC} && \
		pax -rwpm -s ',.*\.orig$$,,' \
			${_texmf} ${DESTDIR}${PREFIX}/share; \
	fi
.endfor
	if [ -d ${WRKSRC}/texmf-doc ]; then \
		cd ${WRKSRC} && \
		pax -rwpm -s ',.*\.orig$$,,' texmf-doc/* \
			${DESTDIR}${PREFIX}/share/doc/texmf; \
	fi
	if [ -d ${WRKSRC}/bin ]; then \
		${FIND} ${WRKSRC}/bin -name \*.orig -exec ${RM} {} \; ; \
		${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin; \
		for script in ${WRKSRC}/bin/*; do \
			${INSTALL_SCRIPT} $$script ${DESTDIR}${PREFIX}/bin; \
		done; \
	fi
	if [ -d ${WRKSRC}/man ]; then \
		${FIND} ${WRKSRC}/man -name \*.orig -exec ${RM} {} \; ; \
		${INSTALL_MAN_DIR} -p ${DESTDIR}${PREFIX}/${PKGMANDIR}; \
		for f in ${WRKSRC}/man/*; do \
			d=${DESTDIR}${PREFIX}/${PKGMANDIR}/`${BASENAME} $$f`; \
			${INSTALL_MAN_DIR} $$d; \
			${INSTALL_MAN} $$f/* $$d; \
		done; \
	fi

.if !empty(TEX_FORMAT_NAMES)
.  include "../../print/texlive-tetex/format.mk"
.endif
.if empty(TEX_TEXMF_DIRS) || ${TEX_TEXMF_DIRS} != "none"
.include "../../print/kpathsea/texmf.mk"
.endif
.if !empty(TEX_HYPHEN_DAT) || !empty(TEX_HYPHEN_DEF)
.  include "../../print/texlive-tetex/hyphen.mk"
.endif
.if !empty(TEX_MAP_FILES) || !empty(TEX_MIXEDMAP_FILES)
.  include "../../print/texlive-tetex/map.mk"
.endif

post-extract: _texlive-set-permission _texlive-man
do-install: _texlive-install
