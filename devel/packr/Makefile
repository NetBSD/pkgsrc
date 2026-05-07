# $NetBSD: Makefile,v 1.49 2026/05/07 18:49:55 bsiegert Exp $

DISTNAME=	packr-2.8.1
PKGREVISION=	48
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=gobuffalo/}
GITHUB_PROJECT=	packr

MAINTAINER=		bbartlomiej@gmail.com
HOMEPAGE=		https://github.com/gobuffalo/packr
COMMENT=		Tool for bundling static assets inside Go binaries
LICENSE=		apache-2.0

GO_SRCPATH=		github.com/gobuffalo/packr
GO_BUILD_PATTERN=	"${GO_SRCPATH}/packr"

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
