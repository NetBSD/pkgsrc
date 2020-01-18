# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:33 rillig Exp $

DISTNAME=	antomega
PKGNAME=	tex-${DISTNAME}-0.8
TEXLIVE_REV=	21933

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/antomega
COMMENT=	Alternative language support for Omega/Lambda
LICENSE=	lppl-1.3c

DEPENDS+=	tex-omega-[0-9]*:../../print/tex-omega

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
