# $NetBSD: Makefile,v 1.1 2022/12/19 19:03:09 wiz Exp $

DISTNAME=	syft-0.63.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=anchore/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anchore/syft/
COMMENT=	Generate Software Bill of Materials from container images and file systems
LICENSE=	apache-2.0

USE_LANGUAGES=	c

# build tools?
# https://github.com/anchore/syft/issues/1413
post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/generate
	${RM} ${DESTDIR}${PREFIX}/bin/json

.include "modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
