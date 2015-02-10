# $NetBSD: Makefile,v 1.1 2015/02/10 02:48:23 mef Exp $

DISTNAME=	collectbox
PKGNAME=	tex-${DISTNAME}-0.4b
CATEGORIES=	print
MASTER_SITES=	http://mirrors.ctan.org/macros/latex/contrib/
EXTRACT_SUFX=	.zip

HOMEPAGE=	http://www.ctan.org/pkg/collectbox
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Collect and process macro arguments as boxes
LICENSE=	lppl-1.3c

BUILD_DEPENDS+=	web2c-[0-9]*:../../print/web2c
BUILD_DEPENDS+=	tex-tetex-[0-9]*:../../print/tex-tetex
BUILD_DEPENDS+=	tex-ydoc-[0-9]*:../../print/tex-ydoc
BUILD_DEPENDS+=	teTeX-texmf-[0-9]*:../../print/teTeX3-texmf

INSTALL_PATH=	share/texmf-dist/tex/latex/collectbox
AUTO_MKDIRS=	yes

do-build:
	(cd ${WRKSRC}; tex collectbox.ins )

do-install:
.for i in dtx ins sty
	(cd ${WRKSRC}; \
	${INSTALL_DATA} collectbox.${i} ${DESTDIR}${PREFIX}/${INSTALL_PATH} )
.endfor

.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
