# $NetBSD: Makefile,v 1.10 2023/04/02 11:48:20 markd Exp $

DISTNAME=	urlbst
PKGNAME=	tex-${DISTNAME}-0.9.1
TEXLIVE_REV=	65694

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/urlbst
COMMENT=	Web support for BibTeX
LICENSE=	gnu-gpl-v2 AND lppl-1.3c

USE_TOOLS+=	perl:run
REPLACE_PERL+=	bin/urlbst

INSTALLATION_DIRS+=	bin

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/urlbst/urlbst ${WRKSRC}/bin/urlbst

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
