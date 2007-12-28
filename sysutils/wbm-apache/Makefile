# $NetBSD: Makefile,v 1.7 2007/12/28 05:24:58 obache Exp $

WBM_NAME=	apache
PKGREVISION=	2

COMMENT=	Webmin module for configuring Apache servers

.include "../../sysutils/webmin/wbm.mk"

CONF_FILES_PERMS+=	${WBM_EGDIR}/${WBM_NAME}/site			\
			${PKG_SYSCONFDIR}/${WBM_NAME}/site		\
			${ROOT_USER} ${ROOT_GROUP} 0644

post-build:
	${TOUCH} ${TOUCH_ARGS} ${WRKDIR}/site

post-install:
	${INSTALL_DATA} ${WRKDIR}/site ${WBM_EGDIR}/${WBM_NAME}/site

.include "../../mk/bsd.pkg.mk"
