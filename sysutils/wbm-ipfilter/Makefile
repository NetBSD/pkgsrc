# $NetBSD: Makefile,v 1.4 2012/10/23 19:51:32 asau Exp $

WBM_NAME=	ipfilter

WBM_DEPEND_MODULES+=	net

COMMENT=	Webmin module for IPFilter configuration

post-extract:
	cp ${FILESDIR}/ipfilter_config-netbsd ${WRKSRC}/${WBM_NAME}/config-netbsd

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
