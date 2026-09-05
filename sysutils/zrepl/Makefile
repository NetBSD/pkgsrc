# $NetBSD: Makefile,v 1.16 2026/09/05 19:10:02 bsiegert Exp $

DISTNAME=	zrepl-0.6.1
PKGREVISION=	14
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=zrepl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zrepl/zrepl/
COMMENT=	One-stop ZFS backup & replication solution
LICENSE=	mit

ZREPL_FLAGS+=	-X github.com/zrepl/zrepl/version.zreplVersion=${PKGVERSION_NOREV}

GOFLAGS+=		-ldflags "${ZREPL_FLAGS}" -mod=readonly
GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
