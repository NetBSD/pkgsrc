# $NetBSD: Makefile,v 1.6 2017/02/01 12:54:57 mef Exp $

WBM_NAME=	ipfilter

WBM_DEPEND_MODULES+=	net

COMMENT=	Webmin module for IPFilter configuration

post-extract:
	cp ${FILESDIR}/ipfilter_config-netbsd ${WRKSRC}/${WBM_NAME}/config-netbsd

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
