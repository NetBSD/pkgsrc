# $NetBSD: Makefile,v 1.14 2021/07/13 11:36:34 bsiegert Exp $

DISTNAME=	amass-3.11.13
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=OWASP/}
GITHUB_PROJECT=	Amass
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://owasp.org/www-project-amass/
COMMENT=	In-depth Attack Surface Mapping and Asset Discovery
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	./cmd/amass
CHECK_RELRO_SKIP+=	bin/amass

INSTALLATION_DIRS+=	bin share/examples/amass share/examples/amass/wordlists

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/amass ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/config.ini ${DESTDIR}${PREFIX}/share/examples/amass
	${INSTALL_DATA} ${WRKSRC}/examples/wordlists/* ${DESTDIR}${PREFIX}/share/examples/amass/wordlists

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
