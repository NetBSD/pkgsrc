# $NetBSD: Makefile,v 1.1 2020/05/22 03:23:56 markd Exp $

DISTNAME=	quoting
PKGNAME=	tex-${DISTNAME}-0.1c
TEXLIVE_REV=	32818

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/quoting
COMMENT=	Consolidated environment for displayed text
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
