# $NetBSD: Makefile,v 1.1 2015/02/10 02:48:09 mef Exp $

DISTNAME=	adjustbox
PKGNAME=	tex-${DISTNAME}-1.0
CATEGORIES=	print
MASTER_SITES=	http://mirrors.ctan.org/macros/latex/contrib/
EXTRACT_SUFX=	.zip

HOMEPAGE=	http://www.ctan.org/pkg/adjustbox
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphics package-alike macros for general boxes
LICENSE=	lppl-1.3c

BUILD_DEPENDS+=	web2c-[0-9]*:../../print/web2c
# tex not found
BUILD_DEPENDS+=	tex-tetex-[0-9]*:../../print/tex-tetex
# mkfmt tex.fmt not found
BUILD_DEPENDS+=	teTeX-texmf-[0-9]*:../../print/teTeX3-texmf
BUILD_DEPENDS+=	tex-ydoc-[0-9]*:../../print/tex-ydoc

INSTALL_PATH=	share/texmf-dist/tex/latex/adjustbox
AUTO_MKDIRS=	yes

do-build:
	(cd ${WRKSRC}; tex adjustbox.ins )

do-install:
.for i in box compare margin margin2 trim trim2 trim3 viewport viewport2
	(cd ${WRKSRC}; \
	${INSTALL_DATA} ${i}.tex ${DESTDIR}${PREFIX}/${INSTALL_PATH} )
.endfor
.for i in dtx ins pdf
	(cd ${WRKSRC}; \
	${INSTALL_DATA} adjustbox.${i} ${DESTDIR}${PREFIX}/${INSTALL_PATH} )
.endfor
.for i in adjustbox adjcalc trimclip
	(cd ${WRKSRC}; \
	${INSTALL_DATA} ${i}.sty ${DESTDIR}${PREFIX}/${INSTALL_PATH} )
.endfor

# if from texlive 2014
# TEXLIVE_REV=	26555
# .include "../../print/texlive/package.mk"
.include "../../print/kpathsea/texmf.mk"

.include "../../mk/bsd.pkg.mk"
