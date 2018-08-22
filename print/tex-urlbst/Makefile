# $NetBSD: Makefile,v 1.3 2018/08/22 09:46:16 wiz Exp $

DISTNAME=	urlbst
PKGNAME=	tex-${DISTNAME}-0.7
PKGREVISION=	2
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
