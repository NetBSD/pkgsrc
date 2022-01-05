# $NetBSD: Makefile,v 1.16 2022/01/05 08:50:07 wiz Exp $

DISTNAME=	mautrix-hangouts-0.1.4
PKGREVISION=	3
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tulir/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/tulir/mautrix-hangouts
COMMENT=	Matrix-Hangouts puppeting bridge
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3<4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-yarl>=1<2:../../www/py-yarl
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.2<2:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-alembic>=1<2:../../databases/py-alembic
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15.94:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.8<0.10:../../textproc/py-commonmark
DEPENDS+=	${PYPKGPREFIX}-magic>=0.4<0.5:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-hangups>=0.4.12<0.5:../../chat/py-hangups
DEPENDS+=	${PYPKGPREFIX}-mautrix>=0.8.2:../../chat/py-mautrix

USE_TOOLS+=	pax
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

EGG_NAME=	mautrix_hangouts-${PKGVERSION_NOREV}+dev.unknown

INSTALLATION_DIRS+=	share/mautrix-hangouts

post-install:
	mv ${DESTDIR}${PREFIX}/alembic ${DESTDIR}${PREFIX}/alembic.ini \
		${DESTDIR}${PREFIX}/example-config.yaml \
		${DESTDIR}${PREFIX}/share/mautrix-hangouts/
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/mautrix_hangouts && \
		${PAX} -wr example-config.yaml \
		${DESTDIR}${PREFIX}/share/mautrix-hangouts/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
