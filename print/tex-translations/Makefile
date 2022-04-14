# $NetBSD: Makefile,v 1.3 2022/04/14 03:39:52 markd Exp $

DISTNAME=	translations
PKGNAME=	tex-${DISTNAME}-1.12
TEXLIVE_REV=	61896

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/translations
COMMENT=	Internationalisation of LaTeX2e packages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
