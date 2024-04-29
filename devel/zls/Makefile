# $NetBSD: Makefile,v 1.1 2024/04/29 13:27:52 nikita Exp $

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

.include "zig-depends.mk"

.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
