# $NetBSD: Makefile,v 1.51 2023/05/05 19:37:36 bsiegert Exp $

DISTNAME=		mkcert-1.4.4
PKGNAME=		${DISTNAME:S/^/go-/}
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=FiloSottile/}
GITHUB_PROJECT=		mkcert
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://mkcert.dev/
COMMENT=		Make locally trusted development certificates
LICENSE=		modified-bsd

post-patch:
	cd ${WRKSRC} && cp truststore_linux.go truststore_netbsd.go

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
