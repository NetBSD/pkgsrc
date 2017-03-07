# $NetBSD: Makefile,v 1.2 2017/03/07 08:26:17 markd Exp $

DISTNAME=	urlbst
PKGNAME=	tex-${DISTNAME}-0.7
PKGREVISION=	1
TEXLIVE_REV=	29803

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/urlbst
COMMENT=	Web support for BibTeX
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
REPLACE_PERL+=	bin/urlbst

INSTALLATION_DIRS+=	bin

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/urlbst/urlbst ${WRKSRC}/bin/urlbst

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
