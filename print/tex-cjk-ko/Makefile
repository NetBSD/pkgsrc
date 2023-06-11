# $NetBSD: Makefile,v 1.10 2023/06/11 05:37:27 markd Exp $

DISTNAME=	cjk-ko
PKGNAME=	tex-${DISTNAME}-2.4
TEXLIVE_REV=	67252

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cjk-ko
COMMENT=	Extension of the CJK package for Korean typesetting
LICENSE=	gnu-gpl-v2 AND lppl-1.3c AND public-domain

DEPENDS+=	tex-cjk-[0-9]*:../../print/tex-cjk

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
