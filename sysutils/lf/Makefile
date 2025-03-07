# $NetBSD: Makefile,v 1.81 2025/03/07 20:54:30 bsiegert Exp $

DISTNAME=		lf-34
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=gokcehan/}
GITHUB_TAG=		r${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/gokcehan/lf
COMMENT=		Terminal file manager
LICENSE=		2-clause-bsd

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 share/applications share/examples/lf

post-install:
	${INSTALL_DATA} ${WRKSRC}/lf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/lf.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/etc/* ${DESTDIR}${PREFIX}/share/examples/lf

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
