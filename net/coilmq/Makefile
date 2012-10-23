# $NetBSD: Makefile,v 1.4 2012/10/23 17:18:15 asau Exp $
#

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

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	distribute_setup.py coilmq/start.py

SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	post-patch
SUBST_FILES.cfg=	coilmq/config/__init__.py
SUBST_SED.cfg=		-e 's,/path/to/config.cfg,${PKG_SYSCONFDIR}/coilmq/defaults.cfg,'

.include "../../lang/python/egg.mk"

# setup.py has python distribute as a dependency
.if ${_PYTHON_VERSION} < 31
SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,distribute,setuptools,'
.endif

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

.include "../../mk/bsd.pkg.mk"
