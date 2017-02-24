# $NetBSD: Makefile,v 1.8 2017/02/24 14:33:38 mef Exp $

PKGNAME=	wbm-${WBM_NAME}-${WBM_MOD_REV}
DISTNAME=	${WBM_NAME}-${WBM_MOD_REV}.gpl
MASTER_SITES=	http://download.webmin.com/download/virtualmin/

WBM_NAME=	virtual-server
WBM_STD_MODULE=	no
WBM_MOD_REV=	5.05
WBM_DEPEND_MODULES=	net quota useradmin sendmail apache mysql

COMMENT=	Webmin module to allow users to control their own virtual servers

#post-install:
#	(cd ${DESTDIR}${PREFIX} ; \
#	${CHMOD} +x share/webmin/virtual-server/newfeatures-gpl;\
#	${FIND} share/webmin/virtual-server -name \*pl -exec ${CHMOD} -x '{}' \; )

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
