# $NetBSD: Makefile,v 1.7 2020/08/31 18:11:05 wiz Exp $

DISTNAME=	urlbst
PKGNAME=	tex-${DISTNAME}-0.8
PKGREVISION=	2
TEXLIVE_REV=	51530

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

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
