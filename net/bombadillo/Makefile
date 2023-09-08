# $NetBSD: Makefile,v 1.23 2023/09/08 19:06:05 bsiegert Exp $

DISTNAME=	2.4.0
PKGNAME=	bombadillo-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	https://tildegit.org/sloum/bombadillo/archive/
DIST_SUBDIR=	bombadillo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bombadillo.colorfield.space/
COMMENT=	Gopher/Gemini client for the terminal
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/bombadillo

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
