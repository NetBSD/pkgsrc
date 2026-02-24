# $NetBSD: Makefile,v 1.60 2026/02/24 08:45:34 bsiegert Exp $

DISTNAME=		age-1.3.1
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=FiloSottile/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		leot@NetBSD.org
HOMEPAGE=		https://github.com/FiloSottile/age/
COMMENT=		Simple, modern and secure encryption tool
LICENSE=		modified-bsd

.include "go-modules.mk"

GOFLAGS=		-ldflags "-X main.Version=v${PKGVERSION_NOREV}"
GO_BUILD_PATTERN+=	filippo.io/age/cmd/...

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
.for f in age-inspect.1 age-keygen.1 age-plugin-batchpass.1 age.1
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
