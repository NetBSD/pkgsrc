# $NetBSD: Makefile,v 1.55.2.1 2025/04/05 20:45:04 maya Exp $

DISTNAME=	gunison-0.1.0
PKGREVISION=	53
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=vfaronov/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vfaronov/gunison
COMMENT=	GTK3 frontend for unison
LICENSE=	mit

USE_TOOLS+=	pkg-config

GO_BUILD_PATTERN=	.

CHECK_RELRO_SKIP=	bin/gunison

.include "go-modules.mk"

.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
