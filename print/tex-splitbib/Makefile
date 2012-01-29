# $NetBSD: Makefile,v 1.1.1.1 2012/01/29 11:55:42 cheusov Exp $

DISTNAME=	splitbib
PKGNAME=	tex-${DISTNAME}-20051222
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/macros/latex/contrib/splitbib/
COMMENT=	Split and reorder your bibliography

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

INSTALLATION_DIRS=	share/texmf-dist/doc/latex/splitbib \
			share/texmf-dist/tex/latex/splitbib

.include "../../print/kpathsea/texmf.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/splitbib.sty \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/splitbib/
	${INSTALL_DATA} ${WRKSRC}/splitbib.pdf \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/splitbib/

.include "../../mk/bsd.pkg.mk"
