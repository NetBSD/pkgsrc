# $NetBSD: Makefile,v 1.2 2019/12/06 20:18:48 markd Exp $

DISTNAME=	antomega
PKGNAME=	tex-${DISTNAME}-0.8
TEXLIVE_REV=	21933

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/antomega
COMMENT=	Alternative language support for Omega/Lambda
LICENSE=	lppl-1.3c

DEPENDS+=	tex-omega-[0-9]*:../../print/tex-omega

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
