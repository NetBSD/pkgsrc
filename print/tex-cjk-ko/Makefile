# $NetBSD: Makefile,v 1.8 2022/04/08 05:31:33 markd Exp $

DISTNAME=	cjk-ko
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	60079

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cjk-ko
COMMENT=	Extension of the CJK package for Korean typesetting
LICENSE=	gnu-gpl-v2 AND lppl-1.3c AND public-domain

DEPENDS+=	tex-cjk-[0-9]*:../../print/tex-cjk

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
