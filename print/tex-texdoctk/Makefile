# $NetBSD: Makefile,v 1.1 2019/02/01 23:35:50 markd Exp $

DISTNAME=	texdoctk
PKGNAME=	tex-${DISTNAME}-0.6.0
TEXLIVE_REV=	47978

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texdoctk
COMMENT=	Easy access to package documentation
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk

REPLACE_PERL=	bin/texdoctk

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texdoctk/texdoctk.pl \
		${WRKSRC}/bin/texdoctk
	${RMDIR} ${WRKSRC}/texmf-dist/scripts/texdoctk

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
