# $NetBSD: Makefile,v 1.11 2024/03/20 09:54:30 markd Exp $

DISTNAME=	cjk-ko
PKGNAME=	tex-${DISTNAME}-2.5
TEXLIVE_REV=	70300

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cjk-ko
COMMENT=	Extension of the CJK package for Korean typesetting
LICENSE=	gnu-gpl-v2 AND lppl-1.3c AND public-domain

DEPENDS+=	tex-cjk-[0-9]*:../../print/tex-cjk

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
