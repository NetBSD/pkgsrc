# $NetBSD: Makefile,v 1.37 2023/01/11 17:28:29 bsiegert Exp $

DISTNAME=	micro-2.0.11
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=zyedidia/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://micro-editor.github.io/
COMMENT=	Modern and intuitive terminal-based text editor
LICENSE=	mit

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

GO_BUILD_PATTERN=	./cmd/micro
GO_LDFLAGS+=		-X github.com/zyedidia/micro/v2/internal/util.Version=${PKGVERSION_NOREV}
GO_LDFLAGS+=		-X github.com/zyedidia/micro/v2/internal/util.CommitHash=${GITHUB_TAG}
GO_ARGS+=		-ldflags ${GO_LDFLAGS:Q}

do-build:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_ARGS} ${GO_BUILD_PATTERN}

post-install:
	${INSTALL_MAN} ${WRKSRC}/assets/packaging/micro.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
