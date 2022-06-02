# $NetBSD: Makefile,v 1.26 2022/06/02 18:52:05 bsiegert Exp $

DISTNAME=	amass-3.11.13
PKGREVISION=	14
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
