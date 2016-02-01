# $NetBSD: package.mk,v 1.24 2016/02/01 18:47:23 leot Exp $
#
# This Makefile fragment is intended to be included by packages that build
# TeX Live packages.
#
# Note to package developers:
# 
#   * When creating/updating a tex package please set TEXLIVE_USE_CTAN (in
#     order to properly update the distinfo via the "makesum" target) and
#     set TEXLIVE_REV appropriately if it is possible (as described below).
#
# Package-settable variables:
#
# REPLACE_TEXLUA
#	A list of texlua scripts to be installed, relative to ${WRKSRC}.
#
# TEXLIVE_IGNORE_PATTERNS
#	glob patterns for files and directories in ${WRKSRC} that
#	should not be installed.
#
# TEXLIVE_REV
#	String appended to DIST_SUBDIR (useful because the majority of tex
#	packages do not have a revision number in the DISTNAME).
#	To obtain information to be used as TEXLIVE_REV you should use the
#	value of "revision" line usually available in
#	${WRKSRC}/tlpkg/tlpobj/${DISTNAME}.tlpobj
#
# TEX_FORMATS
#	See ../../print/tex-tetex/format.mk.
#
# TEX_HYPHEN_DAT
#	See ../../print/texlive-tetex/hyphen.mk.
#
# TEX_HYPHEN_DEF
#	See ../../print/texlive-tetex/hyphen.mk.
#
# TEX_TEXMF_DIRS
#	See ../../print/kpathsea/texmf.mk.
#
# Keywords: latex tex texlive
#

CATEGORIES?=	print
.if empty(TEXLIVE_USE_CTAN)
MASTER_SITES?=	${MASTER_SITE_BACKUP}
.else
MASTER_SITES?=	${MASTER_SITE_TEX_CTAN:=systems/texlive/tlnet/archive/}
.endif
.if empty(TEXLIVE_REV)
DIST_SUBDIR?=	${PKGNAME_NOREV}
.else
DIST_SUBDIR?=	${PKGBASE:S/-doc$//}-${TEXLIVE_REV}
.endif
EXTRACT_SUFX?=	.tar.xz

HOMEPAGE?=	http://www.tug.org/texlive/

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
	if [ -d ${WRKSRC}/texmf-dist/doc/info ]; then \
		${RM} -f ${WRKSRC}/texmf-dist/doc/info/dir; \
		${MKDIR} ${WRKSRC}/info; \
		${MV} ${WRKSRC}/texmf-dist/doc/info/* ${WRKSRC}/info; \
		${RMDIR} -p ${WRKSRC}/texmf-dist/doc/info || ${TRUE}; \
	fi
	if [ -d ${WRKSRC}/doc/info ]; then \
		${RM} -f ${WRKSRC}/doc/info/dir; \
		${MKDIR} ${WRKSRC}/info; \
		${MV} ${WRKSRC}/doc/info/* ${WRKSRC}/info; \
		${RMDIR} -p ${WRKSRC}/doc/info || ${TRUE}; \
	fi

_texlive-man:
	if [ -d ${WRKSRC}/texmf-dist/doc/man ]; then \
		${MKDIR} ${WRKSRC}/man; \
		${MV} ${WRKSRC}/texmf-dist/doc/man/* ${WRKSRC}/man; \
		${FIND} ${WRKSRC}/man -name \*.pdf -exec ${RM} {} \; ; \
		${RMDIR} -p ${WRKSRC}/texmf-dist/doc/man || ${TRUE}; \
	fi
	if [ -d ${WRKSRC}/doc/man ]; then \
		${MKDIR} ${WRKSRC}/man; \
		${MV} ${WRKSRC}/doc/man/* ${WRKSRC}/man; \
		${FIND} ${WRKSRC}/man -name \*.pdf -exec ${RM} {} \; ; \
		${RMDIR} -p ${WRKSRC}/doc/man || ${TRUE}; \
	fi

_texlive-install:
	if [ -d ${WRKSRC}/texmf -o -d ${WRKSRC}/texmf-dist ]; then \
		_dirs="texmf texmf-dist"; \
		_topdir="${DESTDIR}${PREFIX}/share"; \
	else \
		_dirs="bibtex doc dvips fonts makeindex metafont metapost omega scripts source tex vtex"; \
		_topdir="${DESTDIR}${PREFIX}/share/texmf-dist"; \
	fi; \
	for _dir in $$_dirs; do \
		if [ -d ${WRKSRC}/$$_dir ]; then \
			echo $$_dir; \
			cd ${WRKSRC} && \
			${INSTALL_DATA_DIR} $$_topdir && \
			${PAX} -rwpm -s ',.*\.orig$$,,' \
				$$_dir $$_topdir; \
		fi \
	done
	if [ -d ${WRKSRC}/bin ]; then \
		${FIND} ${WRKSRC}/bin -name \*.orig -exec ${RM} {} \; ; \
		${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin; \
		for script in ${WRKSRC}/bin/*; do \
			${INSTALL_SCRIPT} $$script ${DESTDIR}${PREFIX}/bin; \
		done; \
	fi
	if [ -d ${WRKSRC}/info ]; then \
		${FIND} ${WRKSRC}/info -name \*.orig -exec ${RM} {} \; ; \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PKGINFODIR}; \
		for script in ${WRKSRC}/info/*; do \
			${INSTALL_DATA} $$script ${DESTDIR}${PREFIX}/${PKGINFODIR}; \
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

post-extract: _texlive-set-permission _texlive-info _texlive-man
do-install: _texlive-install
