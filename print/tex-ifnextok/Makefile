# $NetBSD: Makefile,v 1.1 2014/10/01 19:57:29 joerg Exp $

DISTNAME=	ifnextok
PKGNAME=	tex-${DISTNAME}-0.3
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utility macro: peek ahead without ignoring spaces

INSTALLATION_DIRS=	share/texmf-dist/doc/latex/ifnextok \
			share/texmf-dist/tex/latex/ifnextok

do-install:
	${INSTALL_DATA} ${WRKSRC}/ifnextok/ifnextok.pdf \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/ifnextok
	${INSTALL_DATA} ${WRKSRC}/ifnextok/ifnextok.sty \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/ifnextok

.include "../../print/kpathsea/texmf.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
