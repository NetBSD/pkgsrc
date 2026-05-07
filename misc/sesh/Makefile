# $NetBSD: Makefile,v 1.2 2026/05/07 18:49:57 bsiegert Exp $

DISTNAME=		sesh-2.26.1
PKGREVISION=		1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GITHUB:=joshmedeski/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/joshmedeski/sesh
COMMENT=		Smart tmux session manager
LICENSE=		mit

.include "go-modules.mk"

GO_BUILD_PATTERN=	github.com/joshmedeski/sesh/v2
GO_LDFLAGS+=		-X main.version=${PKGVERSION_NOREV}
GOFLAGS+=		-ldflags ${GO_LDFLAGS:Q}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/sesh.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
