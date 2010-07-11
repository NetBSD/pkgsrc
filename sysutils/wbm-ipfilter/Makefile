# $NetBSD: Makefile,v 1.3 2010/07/11 17:41:04 joerg Exp $

WBM_NAME=	ipfilter

WBM_DEPEND_MODULES+=	net

COMMENT=	Webmin module for IPFilter configuration

PKG_DESTDIR_SUPPORT=	user-destdir

post-extract:
	cp ${FILESDIR}/ipfilter_config-netbsd ${WRKSRC}/${WBM_NAME}/config-netbsd

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
