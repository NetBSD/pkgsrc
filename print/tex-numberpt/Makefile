# $NetBSD: Makefile,v 1.2 2019/12/06 20:22:56 markd Exp $

DISTNAME=	numberpt
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	51640

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/numberpt
COMMENT=	Counters spelled out in Portuguese
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
