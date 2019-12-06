# $NetBSD: Makefile,v 1.13 2019/12/06 20:23:26 markd Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50627

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/texdoc
COMMENT=	Documentation access for TeX distributions
LICENSE=	gnu-gpl-v2

REPLACE_TEXLUA=		bin/texdoc

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texdoc/texdoc.tlu \
		${WRKSRC}/bin/texdoc

.include "../../mk/bsd.pkg.mk"
