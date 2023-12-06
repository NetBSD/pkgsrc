# $NetBSD: Makefile,v 1.55.2.2 2023/12/06 12:08:52 spz Exp $

DISTNAME=	goreman-0.3.7
PKGNAME=	go-${DISTNAME}
PKGREVISION=	28
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
