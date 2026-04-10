# $NetBSD: Makefile,v 1.72 2026/04/10 21:01:16 sjmulder Exp $

DISTNAME=	micro-2.0.15
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=micro-editor/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://micro-editor.github.io/
COMMENT=	Modern and intuitive terminal-based text editor
LICENSE=	mit

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/applications share/doc/micro

GO_LDFLAGS+=		-X github.com/zyedidia/micro/v2/internal/util.Version=${PKGVERSION_NOREV}
GO_LDFLAGS+=		-X github.com/zyedidia/micro/v2/internal/util.CommitHash=${GITHUB_TAG}
GOFLAGS=		-ldflags ${GO_LDFLAGS:Q}
GO_BUILD_PATTERN=	./cmd/micro

post-install:
	${INSTALL_MAN}  ${WRKSRC}/assets/packaging/micro.1       ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/assets/packaging/micro.desktop ${DESTDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/README.md           ${DESTDIR}${PREFIX}/share/doc/micro/
	${INSTALL_DATA} ${WRKSRC}/LICENSE             ${DESTDIR}${PREFIX}/share/doc/micro/
	${INSTALL_DATA} ${WRKSRC}/LICENSE-THIRD-PARTY ${DESTDIR}${PREFIX}/share/doc/micro/

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
