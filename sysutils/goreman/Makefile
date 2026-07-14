# $NetBSD: Makefile,v 1.81.2.1 2026/07/14 00:36:05 maya Exp $

DISTNAME=	goreman-0.3.7
PKGNAME=	go-${DISTNAME}
PKGREVISION=	53
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=mattn/}
GITHUB_PROJECT=	goreman
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/mattn/goreman
COMMENT=	Foreman clone written in Go language
LICENSE=	mit

INSTALLATION_DIRS+=	share/examples/${PKGBASE}

post-install:
	# Remove binaries installed by dependent modules.
	${RM} -f ${DESTDIR}${PREFIX}/bin/colorable
	${RM} -f ${DESTDIR}${PREFIX}/bin/godotenv
	${RM} -f ${DESTDIR}${PREFIX}/bin/mkwinsyscall
	${INSTALL_DATA} ${WRKSRC}/_example/* ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
