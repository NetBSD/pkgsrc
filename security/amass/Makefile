# $NetBSD: Makefile,v 1.42.2.2 2023/12/06 12:08:49 spz Exp $

DISTNAME=	amass-3.22.1
PKGREVISION=	7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=OWASP/}
GITHUB_PROJECT=	Amass
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://owasp.org/www-project-amass/
COMMENT=	In-depth Attack Surface Mapping and Asset Discovery
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	./cmd/amass

INSTALLATION_DIRS+=	share/examples/amass share/examples/amass/wordlists

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/config.ini ${DESTDIR}${PREFIX}/share/examples/amass
	${INSTALL_DATA} ${WRKSRC}/examples/wordlists/* ${DESTDIR}${PREFIX}/share/examples/amass/wordlists

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
