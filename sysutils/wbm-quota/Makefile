# $NetBSD: Makefile,v 1.1.1.1 2006/05/16 15:42:30 jlam Exp $

DISTNAME=	quota
PKGNAME=	wbm-${DISTNAME}-${WBM_VERSION}
DIST_SUBDIR=	webmin-modules-${WBM_VERSION}

# The version is from the module.info file from the extracted distfile.
WBM_VERSION=	1.270

DEPENDS+=	wbm-mount>=1.270:../../sysutils/wbm-mount

HOMEPAGE=	http://www.webmin.com/standard.html
COMMENT=	Webmin module to setup disk quotas

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
