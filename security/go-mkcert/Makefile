# $NetBSD: Makefile,v 1.69 2025/04/05 18:51:25 bsiegert Exp $

DISTNAME=		mkcert-1.4.4
PKGNAME=		${DISTNAME:S/^/go-/}
PKGREVISION=		20
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
