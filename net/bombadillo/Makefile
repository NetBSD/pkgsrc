# $NetBSD: Makefile,v 1.44 2026/01/15 19:54:46 bsiegert Exp $

DISTNAME=	2.4.0
PKGNAME=	bombadillo-${DISTNAME}
PKGREVISION=	27
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
