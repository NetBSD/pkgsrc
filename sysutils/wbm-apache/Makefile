# $NetBSD: Makefile,v 1.2 2007/02/19 21:52:41 joerg Exp $

DISTNAME=	apache
PKGNAME=	wbm-${DISTNAME}-${WBM_VERSION}
DIST_SUBDIR=	webmin-modules-${WBM_VERSION}

# The version is from the module.info file from the extracted distfile.
WBM_VERSION=	1.270

HOMEPAGE=	http://www.webmin.com/standard.html
COMMENT=	Webmin module for configuring Apache servers

BROKEN=		"Distfile broken"

.include "../../sysutils/webmin/wbm.mk"

CONF_FILES_PERMS+=	${WBM_EGDIR}/${WBMNAME}/site			\
			${PKG_SYSCONFDIR}/${WBMNAME}/site		\
			${ROOT_USER} ${ROOT_GROUP} 0644

post-build:
	${TOUCH} ${TOUCH_ARGS} ${WRKDIR}/site

post-install:
	${INSTALL_DATA} ${WRKDIR}/site ${WBM_EGDIR}/${WBMNAME}/site

.include "../../mk/bsd.pkg.mk"
