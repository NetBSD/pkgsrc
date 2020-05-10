# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:37 markd Exp $

DISTNAME=	anonymouspro
PKGNAME=	tex-${DISTNAME}-2.2
PKGREVISION=	1
TEXLIVE_REV=	51631

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/anonymouspro
COMMENT=	Use AnonymousPro fonts with LaTeX
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	AnonymousPro.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
