# $NetBSD: Makefile,v 1.15 2023/01/11 17:28:32 bsiegert Exp $

DISTNAME=	2.3.3
PKGNAME=	bombadillo-${DISTNAME}
PKGREVISION=	14
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
