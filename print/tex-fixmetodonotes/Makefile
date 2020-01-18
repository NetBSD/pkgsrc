# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:09 rillig Exp $

DISTNAME=	fixmetodonotes
PKGNAME=	tex-${DISTNAME}-0.2.2
TEXLIVE_REV=	30168

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fixmetodonotes
COMMENT=	Add notes on document development
LICENSE=	public-domain

DEPENDS+=	tex-tocloft-[0-9]*:../../print/tex-tocloft
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
