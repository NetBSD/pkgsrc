# $NetBSD: Makefile,v 1.14 2019/08/11 13:23:18 wiz Exp $

WBM_NAME=	apache

COMMENT=	Webmin module for configuring Apache servers
PKGREVISION=	2

.include "../../sysutils/webmin/wbm.mk"

CONF_FILES+=	${WBM_EGDIR}/${WBM_NAME}/site \
		${PKG_SYSCONFDIR}/${WBM_NAME}/site

post-build:
	${TOUCH} ${TOUCH_ARGS} ${WRKDIR}/site

post-install:
	${INSTALL_DATA} ${WRKDIR}/site ${DESTDIR}${WBM_EGDIR}/${WBM_NAME}/site

.include "../../mk/bsd.pkg.mk"
