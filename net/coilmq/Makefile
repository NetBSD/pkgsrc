# $NetBSD: Makefile,v 1.6 2014/05/09 07:37:14 wiz Exp $

DISTNAME=	CoilMQ-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	http://coilmq.googlecode.com/files/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://code.google.com/p/coilmq/
COMMENT=	Lightweight Python STOMP message broker
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.6.9:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-stompclient>=0.3.2:../../devel/py-stompclient
DEPENDS+=	${PYPKGPREFIX}-daemon>=1.5.5:../../devel/py-daemon

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	distribute_setup.py coilmq/start.py

SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	post-patch
SUBST_FILES.cfg=	coilmq/config/__init__.py
SUBST_SED.cfg=		-e 's,/path/to/config.cfg,${PKG_SYSCONFDIR}/coilmq/defaults.cfg,'

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-stompclient, py-daemon

EGDIR=			${PREFIX}/share/examples/coilmq

INSTALLATION_DIRS+=	${EGDIR} ${PKG_SYSCONFDIR}/coilmq

CONF_FILES=		${EGDIR}/defaults.cfg				\
			${PKG_SYSCONFDIR}/coilmq/defaults.cfg		\
			${EGDIR}/coilmq.cfg-sample			\
			${PKG_SYSCONFDIR}/coilmq/coilmq.cfg

post-install:
	${INSTALL_DATA} ${WRKSRC}/coilmq/config/defaults.cfg		\
		${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/coilmq/config/coilmq.cfg-sample	\
		${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
