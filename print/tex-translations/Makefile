# $NetBSD: Makefile,v 1.2 2021/02/20 11:04:57 markd Exp $

DISTNAME=	translations
PKGNAME=	tex-${DISTNAME}-1.10a
TEXLIVE_REV=	57461

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/translations
COMMENT=	Internationalisation of LaTeX2e packages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
