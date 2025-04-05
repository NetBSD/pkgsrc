# $NetBSD: Makefile,v 1.52.2.1 2025/04/05 20:45:12 maya Exp $

DISTNAME=		direnv-2.35.0
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=direnv/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		leot@NetBSD.org
HOMEPAGE=		https://direnv.net/
COMMENT=		Environment switcher for the shell
LICENSE=		mit

# Do not build `script/' binaries
GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/*.1 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
