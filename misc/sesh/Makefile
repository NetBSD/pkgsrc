# $NetBSD: Makefile,v 1.3.2.1 2026/07/14 00:35:53 maya Exp $

DISTNAME=		sesh-2.26.1
PKGREVISION=		3
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
