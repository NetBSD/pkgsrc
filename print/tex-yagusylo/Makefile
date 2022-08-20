# $NetBSD: Makefile,v 1.1 2022/08/20 23:27:37 wiz Exp $

DISTNAME=	yagusylo
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	29803

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/yagusylo
COMMENT=	Symbol loader
LICENSE=	lppl-1.3c

DEPENDS+=	tex-xifthen-[0-9]*:../../devel/tex-xifthen
# suffix
DEPENDS+=	tex-bigfoot-[0-9]*:../../print/tex-bigfoot
DEPENDS+=	tex-xargs-[0-9]*:../../print/tex-xargs
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
