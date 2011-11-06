# $NetBSD: package.mk,v 1.11 2011/11/06 08:43:28 minskim Exp $
#
# This Makefile fragment is intended to be included by packages that build
# TeX Live packages.
#
# Package-settable variables:
#
# REPLACE_TEXLUA
#	A list of texlua scripts to be installed, relative to ${WRKSRC}.
#
# TEX_FORMATS
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
.if empty(TEXLIVE_USE_CTAN)
MASTER_SITES?=	${MASTER_SITE_BACKUP}
.else
MASTER_SITES?=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/archive/}
.endif
.if empty(TEXLIVE_REV)
DIST_SUBDIR?=	${PKGNAME_NOREV}
.else
DIST_SUBDIR?=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}
.endif
EXTRACT_SUFX?=	.tar.xz

HOMEPAGE?=	http://www.tug.org/texlive/

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

NO_BUILD?=	yes
WRKSRC?=	${WRKDIR}

.if defined(REPLACE_TEXLUA)
DEPENDS+=	luatex-[0-9]*:../../print/luatex

REPLACE_INTERPRETER=	texlua
REPLACE.texlua.old=	.*texlua
REPLACE.texlua.new=	${LOCALBASE}/bin/texlua
REPLACE_FILES.texlua=	${REPLACE_TEXLUA}
.endif

.if empty(TEX_TEXMF_DIRS)
_dirs=		bibtex doc dvips fonts makeindex metafont metapost \
		omega scripts source tex vtex
_topdir=	${DESTDIR}${PREFIX}/share/texmf-dist
.else
_dirs=		texmf texmf-dist
_topdir=	${DESTDIR}${PREFIX}/share
.endif

.PHONY: _texlive-set-permission _texlive-info _texlive-man _texlive-install
_texlive-set-permission:
.for _pat in ${TEXLIVE_IGNORE_PATTERNS}
	${RM} -rf ${WRKSRC}/${_pat}
.endfor
.for _dir in ${_dirs}
	if [ -d ${WRKSRC}/${_dir} ]; then \
	  ${FIND} ${WRKSRC}/${_dir} -type d -exec ${CHMOD} ${PKGDIRMODE} {} \; ; \
	  ${FIND} ${WRKSRC}/${_dir} -type f -exec ${CHMOD} ${SHAREMODE} {} \; ; \
	fi
.endfor

_texlive-info:
	if [ -d ${WRKSRC}/texmf/doc/info ]; then \
		${RM} -f ${WRKSRC}/texmf/doc/info/dir; \
		${MKDIR} ${WRKSRC}/info; \
		${MV} ${WRKSRC}/texmf/doc/info/* ${WRKSRC}/info; \
		${RMDIR} -p ${WRKSRC}/texmf/doc/info || ${TRUE}; \
	fi

_texlive-man:
	if [ -d ${WRKSRC}/texmf/doc/man ]; then \
		${MKDIR} ${WRKSRC}/man; \
		${MV} ${WRKSRC}/texmf/doc/man/* ${WRKSRC}/man; \
		${FIND} ${WRKSRC}/man -name \*.pdf -exec ${RM} {} \; ; \
		${RMDIR} -p ${WRKSRC}/texmf/doc/man || ${TRUE}; \
	fi

_texlive-install:
.for _dir in ${_dirs}
	if [ -d ${WRKSRC}/${_dir} ]; then \
		cd ${WRKSRC} && \
		${MKDIR} ${_topdir} && \
		pax -rwpm -s ',.*\.orig$$,,' \
			${_dir} ${_topdir}; \
	fi
.endfor
	if [ -d ${WRKSRC}/bin ]; then \
		${FIND} ${WRKSRC}/bin -name \*.orig -exec ${RM} {} \; ; \
		${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin; \
		for script in ${WRKSRC}/bin/*; do \
			${INSTALL_SCRIPT} $$script ${DESTDIR}${PREFIX}/bin; \
		done; \
	fi
	if [ -d ${WRKSRC}/info ]; then \
		${FIND} ${WRKSRC}/info -name \*.orig -exec ${RM} {} \; ; \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/info; \
		for script in ${WRKSRC}/info/*; do \
			${INSTALL_DATA} $$script ${DESTDIR}${PREFIX}/info; \
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

.if empty(TEX_TEXMF_DIRS) || ${TEX_TEXMF_DIRS} != "none"
.  include "../../print/kpathsea/texmf.mk"
.endif
.if !empty(TEX_FORMATS) || !empty(TEX_FORMAT_NAMES)
.  include "../../print/texlive-tetex/format.mk"
.endif
.if !empty(TEX_HYPHEN_DAT) || !empty(TEX_HYPHEN_DEF)
.  include "../../print/texlive-tetex/hyphen.mk"
.endif
.if !empty(TEX_MAP_FILES) || !empty(TEX_MIXEDMAP_FILES)
.  include "../../print/tex-tetex/map.mk"
.endif

post-extract: _texlive-set-permission _texlive-info _texlive-man
do-install: _texlive-install
