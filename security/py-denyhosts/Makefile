# $NetBSD: Makefile,v 1.24 2022/01/19 18:09:08 wiz Exp $

DISTNAME=	denyhosts-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denyhosts/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://denyhosts.sourceforge.net/
COMMENT=	Watch auth log for invalid ssh login attempts and block hosts

EGDIR=		share/examples/denyhosts
INSTALLATION_DIRS+=	${EGDIR}

CONF_FILES+=	${PREFIX}/${EGDIR}/denyhosts.conf \
		${PKG_SYSCONFDIR}/denyhosts.conf

FILES_SUBST+=	PYTHONBIN=${PYTHONBIN:Q}

SUBST_CLASSES+=	cf
SUBST_STAGE.cf=	post-configure
SUBST_VARS.cf=	VARBASE PREFIX VARBASE PKG_SYSCONFDIR PYTHONBIN PKGMANDIR
SUBST_FILES.cf=	setup.py denyhosts.conf daemon-control-dist

REPLACE_PYTHON=		daemon-control-dist plugins/test_deny.py setup.py
REPLACE_PYTHON+=	scripts/restricted_from_invalid.py
REPLACE_PYTHON+=	scripts/restricted_from_passwd.py

PYTHON_SELF_CONFLICT=		yes

RCD_SCRIPTS+=	denyhosts
SMF_NAME=	denyhost

DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

post-install:
	mv ${DESTDIR}/${PKG_SYSCONFDIR}/denyhosts.conf \
		${DESTDIR}/${PREFIX}/${EGDIR}/denyhosts.conf

EGG_NAME=	DenyHosts-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
