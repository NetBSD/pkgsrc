# $NetBSD: Makefile,v 1.1 2022/04/16 01:15:37 markd Exp $

DISTNAME=	zitie
PKGNAME=	tex-${DISTNAME}-1.4.0
TEXLIVE_REV=	60676

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/zitie
COMMENT=	Create CJK character calligraphy practicing sheets
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3experimental-[0-9]*:../../devel/tex-l3experimental
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
