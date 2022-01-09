# $NetBSD: Makefile,v 1.30 2022/01/09 20:10:35 bsiegert Exp $

# When updating changelog is available in
# ${WRKSRC}/docs/content/changelog.md
DISTNAME=	rclone-1.56.0
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=rclone/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://rclone.org/
COMMENT=	Rsync for cloud storage
LICENSE=	mit

GO_BUILD_PATTERN=	--ldflags "-X github.com/rclone/rclone/fs.Version=${PKGVERSION_NOREV}"
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/rclone.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
