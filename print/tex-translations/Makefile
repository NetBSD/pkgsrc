# $NetBSD: Makefile,v 1.1 2020/05/22 03:27:50 markd Exp $

DISTNAME=	translations
PKGNAME=	tex-${DISTNAME}-1.8b
TEXLIVE_REV=	54929

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/translations
COMMENT=	Internationalisation of LaTeX2e packages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
