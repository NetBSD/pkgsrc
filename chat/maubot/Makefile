# $NetBSD: Makefile,v 1.6 2021/12/30 13:05:28 adam Exp $

DISTNAME=	maubot-0.1.0
PKGREVISION=	2
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/maubot/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/maubot/maubot
COMMENT=	Plugin-based Matrix bot system
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-mautrix>=0.7.9:../../chat/py-mautrix
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3<4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1<2:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-alembic>=1<2:../../databases/py-alembic
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.9<1:../../textproc/py-commonmark
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15.35:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-attrs>=18.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3<4:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-packaging>=10:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-click>=7<8:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4<0.5:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-inquirer>=1<2:../../devel/py-inquirer
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2<3:../../textproc/py-jinja2

USE_LANGUAGES=	# none
 
PYTHON_VERSIONS_INCOMPATIBLE=	27

INSTALLATION_DIRS+=	share/maubot

post-install:
	mv ${DESTDIR}${PREFIX}/alembic ${DESTDIR}${PREFIX}/alembic.ini \
		${DESTDIR}${PREFIX}/example-config.yaml \
		${DESTDIR}${PREFIX}/share/maubot/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
