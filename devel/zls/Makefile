# $NetBSD: Makefile,v 1.3 2024/05/05 20:56:55 nikita Exp $

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

# Temporary required, a zig build system parser is being written.
ALLOW_NETWORK_ACCESS=yes

.include "zig-depends.mk"

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
