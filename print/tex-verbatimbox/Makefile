# $NetBSD: Makefile,v 1.1 2014/10/01 19:59:24 joerg Exp $

DISTNAME=	verbatimbox
PKGNAME=	tex-${DISTNAME}-3.13
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Deposit verbatim text in a box

DEPENDS+=	tex-readarray-[0-9]*:../../print/tex-readarray

INSTALLATION_DIRS=	share/texmf-dist/doc/latex/verbatimbox \
			share/texmf-dist/tex/latex/verbatimbox

do-install:
	${INSTALL_DATA} ${WRKSRC}/verbatimbox/verbatimbox.pdf \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/verbatimbox
	${INSTALL_DATA} ${WRKSRC}/verbatimbox/verbatimbox.sty \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/verbatimbox

.include "../../print/kpathsea/texmf.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
