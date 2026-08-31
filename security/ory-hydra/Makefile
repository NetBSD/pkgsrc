# $NetBSD: Makefile,v 1.7 2026/08/31 19:19:03 bsiegert Exp $

DISTNAME=	hydra-26.2.0
PKGNAME=	ory-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=ory/}
GITHUB_PROJECT=	hydra
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ory/hydra/
COMMENT=	Hardened, OpenID Certified OAuth 2.0 Server and OpenID Connect Provider
LICENSE=	apache-2.0

NO_CONFIGURE=		yes
INSTALLATION_DIRS+=	bin
GOFLAGS=		-tags sqlite,sqlite_omit_load_extension
GOFLAGS+=		-ldflags "-X github.com/ory/hydra/v2/driver/config.Version=${PKGVERSION_NOREV}"
WRKSRC=			${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/hydra ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
