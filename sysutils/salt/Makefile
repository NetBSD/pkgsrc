# $NetBSD: Makefile,v 1.3 2012/02/12 13:40:44 obache Exp $
#

DISTNAME=	salt-0.9.5
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/downloads/saltstack/salt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://saltstack.org/
COMMENT=	Remote execution and configuration management system
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

FETCH_USING=	curl

SUBST_CLASSES+=		fix-paths
SUBST_STAGE.fix-paths=	post-patch
SUBST_MESSAGE.fix-paths=Fixing directory paths.
SUBST_FILES.fix-paths+=	conf/*
SUBST_FILES.fix-paths+=	doc/man/*
SUBST_FILES.fix-paths+=	salt/__init__.py
SUBST_FILES.fix-paths+=	salt/cli/__init__.py
SUBST_FILES.fix-paths+=	salt/client.py
SUBST_FILES.fix-paths+=	salt/config.py
SUBST_FILES.fix-paths+=	salt/modules/mysql.py
SUBST_SED.fix-paths+=	-e "s|/etc/salt|${PKG_SYSCONFDIR}|g"

PKG_SYSCONFSUBDIR=	salt

EGDIR=		${PREFIX}/share/examples/salt
CONF_FILES+=	${EGDIR}/master ${PKG_SYSCONFDIR}/master
CONF_FILES+=	${EGDIR}/minion ${PKG_SYSCONFDIR}/minion

RCD_SCRIPTS+=	salt_master salt_minion

PYTHON_VERSIONS_ACCEPTED=       26
.include "../../lang/python/distutils.mk"
DEPENDS+= zeromq>=2.1.9:../../net/zeromq
DEPENDS+= ${PYPKGPREFIX}-zmq>=2.1.9:../../net/py-zmq
DEPENDS+= ${PYPKGPREFIX}-m2crypto-[0-9]*:../../security/py-m2crypto
DEPENDS+= ${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto
DEPENDS+= ${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../mk/bsd.pkg.mk"
