# $NetBSD: Makefile,v 1.21.2.1 2026/04/22 14:31:57 maya Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	gce_metadata_server-3.93.5
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=salrashid123/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/salrashid123/gce_metadata_server/
COMMENT=	Emulator for the Google Compute Engine Metadata Server
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	./cmd

do-install:
	cd ${WRKDIR}/.gopath/bin && ${INSTALL_PROGRAM} cmd ${DESTDIR}${PREFIX}/bin/gce_metadata_server

.include "go-modules.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
