# $NetBSD: Makefile,v 1.4 2024/06/13 13:46:57 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	gce_metadata_server-3.0.0
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=salrashid123/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/salrashid123/gce_metadata_server/
COMMENT=	Emulator for the Google Compute Engine Metadata Server
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
