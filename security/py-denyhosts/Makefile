# $NetBSD: Makefile,v 1.1.1.1 2007/08/02 17:27:30 he Exp $
#

VER=		2.6
DISTNAME=	DenyHosts-${VER}
PKGNAME=	${PYPKGPREFIX}-denyhosts-${VER}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=denyhosts/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://denyhosts.sourceforge.net/
COMMENT=	Watch auth log for invalid ssh login attempts and block hosts

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_ACCEPTED=	24 23

CONF_FILES+=	${PREFIX}/share/denyhosts/denyhosts.cfg-dist \
		${PREFIX}/etc/denyhosts.conf

SUBST_CLASSES+=	cf
SUBST_STAGE.cf= post-configure
SUBST_VARS.cf=	VARBASE PREFIX VARBASE PKG_SYSCONFDIR PYTHONBIN
SUBST_FILES.cf=	setup.py denyhosts.cfg-dist daemon-control-dist

REPLACE_PYTHON=	plugins/test_deny.py
REPLACE_PYTHON+= scripts/restricted_from_invalid.py
REPLACE_PYTHON+= scripts/restricted_from_passwd.py

RCD_SCRIPTS+=	denyhosts

post-configure:
	${RM} ${WRKDIR}/${DISTNAME}/scripts/*.orig

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
