# $NetBSD: Makefile,v 1.14 2019/04/26 13:14:07 maya Exp $

DISTNAME=	CoilMQ-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://coilmq.googlecode.com/files/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/hozn/coilmq/
COMMENT=	Lightweight Python STOMP message broker
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.6.9:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-stompclient>=0.3.2:../../devel/py-stompclient
DEPENDS+=	${PYPKGPREFIX}-daemon>=1.5.5:../../devel/py-daemon

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	distribute_setup.py coilmq/start.py

PKG_SYSCONFSUBDIR=	coilmq

SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	pre-configure
SUBST_FILES.cfg=	coilmq/config/__init__.py
SUBST_SED.cfg=		-e 's,/path/to/config.cfg,${PKG_SYSCONFDIR}/defaults.cfg,'

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-stompclient, py-daemon

EGDIR=			${PREFIX}/share/examples/coilmq

INSTALLATION_DIRS+=	${EGDIR}

CONF_FILES=		${EGDIR}/defaults.cfg				\
			${PKG_SYSCONFDIR}/defaults.cfg			\
			${EGDIR}/coilmq.cfg-sample			\
			${PKG_SYSCONFDIR}/coilmq.cfg

post-install:
	${INSTALL_DATA} ${WRKSRC}/coilmq/config/defaults.cfg		\
		${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/coilmq/config/coilmq.cfg-sample	\
		${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
