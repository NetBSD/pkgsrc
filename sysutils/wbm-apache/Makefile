# $NetBSD: Makefile,v 1.9 2010/07/11 17:41:01 joerg Exp $

WBM_NAME=	apache

COMMENT=	Webmin module for configuring Apache servers

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../sysutils/webmin/wbm.mk"

CONF_FILES+=	${WBM_EGDIR}/${WBM_NAME}/site \
		${PKG_SYSCONFDIR}/${WBM_NAME}/site

post-build:
	${TOUCH} ${TOUCH_ARGS} ${WRKDIR}/site

post-install:
	${INSTALL_DATA} ${WRKDIR}/site ${DESTDIR}${WBM_EGDIR}/${WBM_NAME}/site

.include "../../mk/bsd.pkg.mk"
