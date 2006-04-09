# $NetBSD: Makefile,v 1.1.1.1 2006/04/09 22:07:54 minskim Exp $

DISTNAME=	memhangul-ucs-1.44c
PKGNAME=	tex-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	http://my.ktug.or.kr/~karnes/testtest/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://faq.ktug.or.kr/faq/MemhangulClass
COMMENT=	Korean support in memoir

DEPENDS+=	tex-dhucs>=2.6:../../print/tex-dhucs
DEPENDS+=	tex-memoir>=1.618:../../print/tex-memoir

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_DIRS+=	texmf-1.2

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/latex/memhangul
.for f in appendixtest.tex doeunbike.bb doeunbike.jpg memucstest.tex
	${INSTALL_DATA} ${WRKSRC}/doc/memhangul-ucs/${f} \
		${PKG_LOCALTEXMFPREFIX}/doc/latex/memhangul
.endfor
	${INSTALL_DATA} ${WRKSRC}/fonts/cmap/UTF8-UCS2 \
		${PKG_LOCALTEXMFPREFIX}/fonts/cmap/
	${INSTALL_DATA} ${WRKSRC}/makeindex/memucs-manual.ist \
		${PKG_LOCALTEXMFPREFIX}/makeindex/
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/memhangul
	${INSTALL_DATA} ${WRKSRC}/tex/latex/memhangul/*.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/memhangul/

.include "../../mk/bsd.pkg.mk"
