# $NetBSD: Makefile,v 1.64 2024/06/13 13:47:07 bsiegert Exp $

DISTNAME=		mkcert-1.4.4
PKGNAME=		${DISTNAME:S/^/go-/}
PKGREVISION=		15
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=FiloSottile/}
GITHUB_PROJECT=		mkcert
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://mkcert.dev/
COMMENT=		Make locally trusted development certificates
LICENSE=		modified-bsd

DEPENDS+=		nss-[0-9]*:../../devel/nss

post-patch:
	cd ${WRKSRC} && cp truststore_linux.go truststore_netbsd.go

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
