# $NetBSD: Makefile,v 1.7 2020/07/29 10:28:29 mef Exp $

WBM_NAME=	ipfilter

WBM_DEPEND_MODULES+=	net

SUBST_CLASSES+=		os
SUBST_STAGE.os=		pre-configure
SUBST_FILES.os=		ipfilter/module.info
SUBST_MESSAGE.os=	Add NetBSD for ipfilter, patch always fails at update
SUBST_SED.os=		-e 's/os_support=solaris/os_support=netbsd solaris/'


COMMENT=	Webmin module for IPFilter configuration

post-extract:
	cp ${FILESDIR}/ipfilter_config-netbsd ${WRKSRC}/${WBM_NAME}/config-netbsd

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
