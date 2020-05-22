# $NetBSD: Makefile,v 1.1 2020/05/22 03:28:49 markd Exp $

DISTNAME=	xpatch
PKGNAME=	tex-${DISTNAME}-0.3
TEXLIVE_REV=	54563

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xpatch
COMMENT=	Extending etoolbox patching commands
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
