# $NetBSD: Makefile,v 1.1.1.1 2008/06/10 02:20:42 jnemeth Exp $

PKGNAME=	wbm-${WBM_NAME}-${WBM_MOD_REV}
DISTNAME=	${WBM_NAME}-${WBM_MOD_REV}.gpl
MASTER_SITES=	http://download.webmin.com/download/virtualmin/

WBM_NAME=	virtual-server
WBM_STD_MODULE=	no
WBM_MOD_REV=	3.572
WBM_DEPEND_MODULES=	net quota

COMMENT=	Webmin module to allow users to control their own virtual servers

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
