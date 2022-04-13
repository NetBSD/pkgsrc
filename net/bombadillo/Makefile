# $NetBSD: Makefile,v 1.5 2022/04/13 07:50:52 bsiegert Exp $

DISTNAME=	2.3.3
PKGNAME=	bombadillo-${DISTNAME}
PKGREVISION=	4
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
