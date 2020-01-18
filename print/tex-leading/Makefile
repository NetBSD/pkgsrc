# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:24 rillig Exp $

DISTNAME=	leading
PKGNAME=	tex-${DISTNAME}-0.3
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/leading
COMMENT=	Define leading with a length
LICENSE=	lppl-1.3c

DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
