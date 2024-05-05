# $NetBSD: Makefile,v 1.2 2024/05/05 20:50:58 nikita Exp $

DISTNAME=	zls-0.12.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zigtools/}
GITHUB_PROJECT=	zls
GITHUB_TAG=	${PKGVERSION_NOREV}

COMMENT=	Language Server for zig
MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/zigtools/zls/
LICENSE=	mit

ZIGSTRIP=	no

BROKEN=	"Temporary broken as a zig build system parser is being finalised"

.include "zig-depends.mk"

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
