# $NetBSD: Makefile,v 1.1 2015/02/10 02:47:54 mef Exp $

DISTNAME=	ydoc
# actually  0.6 alpha
PKGNAME=	tex-${DISTNAME}-0.6alpha
CATEGORIES=	print
MASTER_SITES=	http://mirrors.ctan.org/install/macros/latex/contrib/
EXTRACT_SUFX=	.tds.zip

HOMEPAGE=	http://www.ctan.org/tex-archive/macros/latex/contrib/ydoc
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Macros for documentation of LaTeX classes and packages
LICENSE=	lppl-1.3c

BUILD_DEPENDS+=	web2c-[0-9]*:../../print/web2c
BUILD_DEPENDS+=	tex-tetex-[0-9]*:../../print/tex-tetex
BUILD_DEPENDS+=	teTeX-texmf-[0-9]*:../../print/teTeX3-texmf

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	ydoc-${PKGVERSION_NOREV}
INSTALL_PATH=	share/texmf-dist/tex/latex/ydoc
AUTO_MKDIRS=	yes

do-build:
	(cd ${WRKDIR}/source/latex/ydoc; tex ydoc.dtx;)

do-install:
.for i in ydoc.cls ydocstrip.tex ydocincl.tex
	(cd ${WRKDIR}/source/latex/ydoc; \
	${INSTALL_DATA} ${i} ${DESTDIR}${PREFIX}/${INSTALL_PATH} )
.endfor
.for i in code desc expl doc
	(cd ${WRKDIR}/source/latex/ydoc; \
	${INSTALL_DATA} ydoc-${i}.sty ${DESTDIR}${PREFIX}/${INSTALL_PATH} )
.endfor

.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
