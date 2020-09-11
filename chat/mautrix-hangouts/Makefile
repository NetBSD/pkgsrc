# $NetBSD: Makefile,v 1.1 2020/09/11 02:47:16 js Exp $

PKGNAME=	mautrix-hangouts-0.1.1
DISTNAME=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	mautrix-hangouts
GITHUB_TAG=	v${PKGVERSION_NOREV}
EGG_NAME=	mautrix_hangouts-${PKGVERSION_NOREV}+dev.unknown
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_GITHUB:=tulir/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/tulir/mautrix-hangouts
COMMENT=	Matrix-Hangouts puppeting bridge
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3<4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.2<2:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-alembic>=1<2:../../databases/py-alembic
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15.94<0.17:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.8<0.10:../../textproc/py-commonmark
DEPENDS+=	${PYPKGPREFIX}-magic>=0.4<0.5:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-tulir-hangups>=0.4.12<0.5:../../chat/py-tulir-hangups
DEPENDS+=	${PYPKGPREFIX}-mautrix>=0.7<0.8:../../chat/py-mautrix

WRKSRC=		${WRKDIR}/mautrix-hangouts-${PKGVERSION_NOREV}
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

INSTALLATION_DIRS+=	share/mautrix-hangouts

post-install:
	mv ${DESTDIR}${PREFIX}/alembic ${DESTDIR}${PREFIX}/alembic.ini \
		${DESTDIR}${PREFIX}/share/mautrix-hangouts/
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/mautrix_hangouts && \
		${PAX} -wr example-config.yaml \
		${DESTDIR}${PREFIX}/share/mautrix-hangouts/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
