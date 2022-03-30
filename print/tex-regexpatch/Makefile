# $NetBSD: Makefile,v 1.1 2022/03/30 16:09:45 micha Exp $

DISTNAME=	regexpatch
PKGNAME=	tex-${DISTNAME}-0.2f
TEXLIVE_REV=	58668

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/regexpatch
COMMENT=	Extending etoolbox patching commands
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
