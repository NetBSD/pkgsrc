# $NetBSD: Makefile,v 1.6 2021/07/13 11:36:36 bsiegert Exp $

GITHUB_PROJECT=	gomuks
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	v${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-0.2.3
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=tulir/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://maunium.net/go/gomuks/
COMMENT=	Terminal Matrix client written in Go
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/gomuks-0.2.3
USE_LANGUAGES=	c
USE_TOOLS=	pkg-config

MAKE_ENV+=	CGO_CFLAGS="`${TOOLS_CMD.pkg-config} --cflags olm` -O2"
MAKE_ENV+=	CGO_LDFLAGS="`${TOOLS_CMD.pkg-config} pkg-config --libs olm`"

GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../security/olm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
