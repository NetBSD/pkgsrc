# $NetBSD: module.mk,v 1.1 2009/04/13 00:03:26 minskim Exp $
#
# This Makefile fragment is inteded to be included by packages that build
# TeX Live packages.
#
# Package-settable variables:
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

NO_CONFIGURE?=	yes
NO_BUILD?=	yes
WRKSRC?=	${WRKDIR}

.PHONY: _texlive-set-permission:
_texlive-set-permission:
.for _pat in ${TEXLIVE_IGNORE_PATTERNS}
	${RM} -rf ${WRKSRC}/${_pat}
.endfor
	${FIND} ${WRKSRC}/texmf* -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/texmf* -type f -exec ${CHMOD} ${SHAREMODE} {} \;

.PHONY: _texlive-install:
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

.include "../../print/kpathsea/texmf.mk"

post-extract: _texlive-set-permission
do-install: _texlive-install

PRINT_PLIST_AWK+=	/^@dirrm share\/texmf/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/doc\/texmf/ { next; }
