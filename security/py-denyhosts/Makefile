# $NetBSD: Makefile,v 1.13 2014/05/09 07:37:18 wiz Exp $

VER=		2.6
DISTNAME=	DenyHosts-${VER}
PKGNAME=	${PYPKGPREFIX}-denyhosts-${VER}
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denyhosts/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://denyhosts.sourceforge.net/
COMMENT=	Watch auth log for invalid ssh login attempts and block hosts

PYDISTUTILSPKG= yes

CONF_FILES+=	${PREFIX}/share/denyhosts/denyhosts.cfg-dist \
		${PREFIX}/etc/denyhosts.conf

FILES_SUBST+=	PYTHONBIN=${PYTHONBIN:Q}

SUBST_CLASSES+=	cf
SUBST_STAGE.cf= post-configure
SUBST_VARS.cf=	VARBASE PREFIX VARBASE PKG_SYSCONFDIR PYTHONBIN
SUBST_FILES.cf=	setup.py denyhosts.cfg-dist daemon-control-dist

REPLACE_PYTHON=	daemon-control-dist plugins/test_deny.py setup.py
REPLACE_PYTHON+= scripts/restricted_from_invalid.py
REPLACE_PYTHON+= scripts/restricted_from_passwd.py

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34

RCD_SCRIPTS+=	denyhosts
SMF_NAME=	denyhost

post-configure:
	${RM} ${WRKDIR}/${DISTNAME}/scripts/*.orig

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
