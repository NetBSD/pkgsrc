# $NetBSD: Makefile,v 1.27 2026/06/05 10:21:44 bsiegert Exp $

DISTNAME=	0.11.6
PKGNAME=	qrcp-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=claudiodangelis/}
DIST_SUBDIR=	qrcp
GITHUB_TAG=	refs/tags/v${DISTNAME}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/claudiodangelis/qrcp/
COMMENT=	Transfer files over Wi-Fi via a QR Code
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c

TOOL_DEPENDS+=	go118>=1.18.0:../../lang/go118

GO_BUILD_PATTERN=	.

.include "./go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
