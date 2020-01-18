# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:30 rillig Exp $

DISTNAME=	milog
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	41610

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/milog
COMMENT=	Fulfilling the documentation duties according to the German minimum wage law
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgfplots-[0-9]*:../../print/tex-pgfplots

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
