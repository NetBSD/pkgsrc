# $NetBSD: Makefile,v 1.1 2017/04/23 05:13:03 markd Exp $

DISTNAME=	entrypoints-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=takluyver/}
GITHUB_PROJECT=	entrypoints

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/takluyver/entrypoints
COMMENT=	Discover and load entry points from installed packages
LICENSE=	mit

NO_BUILD=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"

.if ${PYPKGPREFIX} == py27
DEPENDS+=	${PYPKGPREFIX}-configparser-[0-9]*:../../devel/py-configparser
.endif

USE_LANGUAGES=	# none

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/entrypoints.py ${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../mk/bsd.pkg.mk"
