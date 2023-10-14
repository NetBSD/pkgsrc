# $NetBSD: Makefile,v 1.7 2023/10/14 01:20:18 markd Exp $

DISTNAME=	mailman-3.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mailman/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	GNU mailing list manager
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

DEPENDS+=	${PYPKGPREFIX}-aiosmtpd>=1.4.3:../../mail/py-aiosmtpd
DEPENDS+=	${PYPKGPREFIX}-alembic>=1.6.2:../../databases/py-alembic
DEPENDS+=	${PYPKGPREFIX}-atpublic-[0-9]*:../../devel/py-atpublic
DEPENDS+=	${PYPKGPREFIX}-authheaders>=0.14.0:../../mail/py-authheaders
DEPENDS+=	${PYPKGPREFIX}-authres>=1.0.1:../../mail/py-authres
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dns>=1.14.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-falcon>=3.0.0:../../devel/py-falcon
DEPENDS+=	${PYPKGPREFIX}-flufl.bounce>=4.0:../../mail/py-flufl.bounce
DEPENDS+=	${PYPKGPREFIX}-flufl.i18n>=3.2:../../devel/py-flufl.i18n
DEPENDS+=	${PYPKGPREFIX}-flufl.lock>=5.1:../../devel/py-flufl.lock
DEPENDS+=	${PYPKGPREFIX}-gunicorn-[0-9]*:../../www/py-gunicorn
DEPENDS+=	${PYPKGPREFIX}-lazr.config-[0-9]*:../../devel/py-lazr.config
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-passlib-[0-9]*:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.4.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-zope.component-[0-9]*:../../devel/py-zope.component
DEPENDS+=	${PYPKGPREFIX}-zope.configuration-[0-9]*:../../devel/py-zope.configuration
DEPENDS+=	${PYPKGPREFIX}-zope.event-[0-9]*:../../devel/py-zope.event
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=5.0:../../devel/py-zope.interface

# TEST_DEPENDS
TOOL_DEPENDS+=	${PYPKGPREFIX}-flufl.testing-[0-9]*:../../devel/py-flufl.testing
TOOL_DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
TOOL_DEPENDS+=	${PYPKGPREFIX}-nose2-[0-9]*:../../devel/py-nose2

BUILD_DEFS+=		VARBASE

SUBST_CLASSES+=		fhs
SUBST_STAGE.fhs=	pre-configure
SUBST_FILES.fhs=	src/mailman/config/mailman.cfg
SUBST_FILES.fhs+=	src/mailman/core/initialize.py
SUBST_FILES.fhs+=	crontab.sample
SUBST_MESSAGE.fhs=	Fixing default paths
SUBST_VARS.fhs=		PKG_SYSCONFDIR PREFIX VARBASE

MAILMAN_USER?=		mailman
MAILMAN_GROUP?=		mailman

PKG_GROUPS_VARS+=	MAILMAN_GROUP
PKG_USERS_VARS+=	MAILMAN_USER

PKG_GROUPS=		${MAILMAN_GROUP}
PKG_USERS=		${MAILMAN_USER}:${MAILMAN_GROUP}

PKG_GECOS.${MAILMAN_USER}=	Mailman user
PKG_SHELL.${MAILMAN_USER}=	${SH}

FILES_SUBST+=		MAILMAN_USER=${MAILMAN_USER}
FILES_SUBST+=		MAILMAN_GROUP=${MAILMAN_GROUP}

RCD_SCRIPTS=		mailman3

OWN_DIRS_PERMS+=	${VARBASE}/lib/mailman ${MAILMAN_USER} ${MAILMAN_GROUP} 770
OWN_DIRS_PERMS+=	${VARBASE}/log/mailman ${MAILMAN_USER} ${MAILMAN_GROUP} 770
OWN_DIRS_PERMS+=	${VARBASE}/spool/mailman ${MAILMAN_USER} ${MAILMAN_GROUP} 775
OWN_DIRS_PERMS+=	${VARBASE}/spool/lock/mailman ${MAILMAN_USER} ${MAILMAN_GROUP} 775

EGDIR=			share/examples/mailman3
CONF_FILES_PERMS=	${EGDIR}/mailman.cfg ${PKG_SYSCONFDIR}/mailman.cfg \
			${REAL_ROOT_USER} ${MAILMAN_GROUP} 0640

INSTALLATION_DIRS+=	${EGDIR}

post-patch:
	${CP} ${FILESDIR}/crontab.sample ${WRKSRC}/crontab.sample

post-install:
	${INSTALL_DATA} ${FILESDIR}/mailman.cfg ${DESTDIR}${PREFIX}/${EGDIR}/mailman.cfg
	${INSTALL_DATA} ${WRKSRC}/crontab.sample ${DESTDIR}${PREFIX}/${EGDIR}/crontab.sample

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
