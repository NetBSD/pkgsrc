# $NetBSD: Makefile,v 1.2 2007/04/21 05:23:01 obache Exp $

WBM_NAME=	ipfilter

WBM_DEPEND_MODULES+=	net

COMMENT=	Webmin module for IPFilter configuration

post-extract:
	cp ${FILESDIR}/ipfilter_config-netbsd ${WRKSRC}/${WBM_NAME}/config-netbsd

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
