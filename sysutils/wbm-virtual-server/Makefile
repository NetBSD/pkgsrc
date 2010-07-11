# $NetBSD: Makefile,v 1.4 2010/07/11 17:41:07 joerg Exp $

PKGNAME=	wbm-${WBM_NAME}-${WBM_MOD_REV}
PKGREVISION=	2
DISTNAME=	${WBM_NAME}-${WBM_MOD_REV}.gpl
MASTER_SITES=	http://download.webmin.com/download/virtualmin/

WBM_NAME=	virtual-server
WBM_STD_MODULE=	no
WBM_MOD_REV=	3.572
WBM_DEPEND_MODULES=	net quota useradmin sendmail apache mysql

COMMENT=	Webmin module to allow users to control their own virtual servers

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
