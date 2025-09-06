# $NetBSD: Makefile,v 1.8 2025/09/06 13:17:12 bsiegert Exp $

DISTNAME=	dasel-2.8.1
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=TomWright/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TomWright/dasel/
COMMENT=	Select, put and delete data from JSON, TOML, YAML, XML and CSV
LICENSE=	mit

USE_LANGUAGES=	c

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${MKDIR} ${WRKSRC}/man
	${DESTDIR}${PREFIX}/bin/dasel man -o ${WRKSRC}/man
	${INSTALL_DATA} ${WRKSRC}/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
