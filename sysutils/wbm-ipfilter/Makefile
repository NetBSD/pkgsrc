# $NetBSD: Makefile,v 1.5 2012/12/22 01:49:16 dholland Exp $

WBM_NAME=	ipfilter
PKGREVISION=	1

WBM_DEPEND_MODULES+=	net

COMMENT=	Webmin module for IPFilter configuration

post-extract:
	cp ${FILESDIR}/ipfilter_config-netbsd ${WRKSRC}/${WBM_NAME}/config-netbsd

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
