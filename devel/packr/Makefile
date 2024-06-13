# $NetBSD: Makefile,v 1.33 2024/06/13 13:47:00 bsiegert Exp $

DISTNAME=	packr-2.8.1
PKGREVISION=	32
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
