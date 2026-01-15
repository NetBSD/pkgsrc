# $NetBSD: Makefile,v 1.5 2026/01/15 19:54:56 bsiegert Exp $

DISTNAME=	zrepl-0.6.1
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=zrepl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zrepl/zrepl/
COMMENT=	One-stop ZFS backup & replication solution
LICENSE=	mit

ZREPL_FLAGS+=	-X github.com/zrepl/zrepl/version.zreplVersion=${PKGVERSION_NOREV}

GO_BUILD_PATTERN+=	-ldflags "${ZREPL_FLAGS}"
GO_BUILD_PATTERN+=	-mod=readonly .

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
