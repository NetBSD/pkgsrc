# $NetBSD: Makefile,v 1.4 2020/06/17 09:54:10 bsiegert Exp $

# When updating changelog is available in
# ${WRKSRC}/docs/content/changelog.md
DISTNAME=	rclone-1.52.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=rclone/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://rclone.org/
COMMENT=	Rsync for cloud storage
LICENSE=	mit

GO_DIST_BASE=		${DISTNAME}
GO_SRCPATH=		github.com/rclone/rclone

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CHECK_RELRO_SKIP+=	bin/rclone

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/rclone ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rclone.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
