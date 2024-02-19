# $NetBSD: Makefile,v 1.1 2024/02/19 19:34:45 gdt Exp $

DISTNAME=	0.11.1
PKGNAME=	qrcp-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=claudiodangelis/}
DIST_SUBDIR=	qrcp
GITHUB_TAG=	refs/tags/0.11.1

MAINTAINER=	kevin.bloom@posteo.net
HOMEPAGE=	https://github.com/claudiodangelis/qrcp/
COMMENT=	Transfer files over Wi-Fi via a QR Code
LICENSE=	mit

WRKSRC=		${WRKDIR}/qrcp-0.11.1
USE_LANGUAGES=	c

TOOL_DEPENDS+=	go118>=1.18.0:../../lang/go118

GO_BUILD_PATTERN=	.

.include "./go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
