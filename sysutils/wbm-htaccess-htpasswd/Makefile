# $NetBSD: Makefile,v 1.1.1.1 2006/05/16 21:41:36 jlam Exp $

DISTNAME=	htaccess-htpasswd
PKGNAME=	wbm-${DISTNAME}-${WBM_VERSION}
DIST_SUBDIR=	webmin-modules-${WBM_VERSION}

# The version is from the module.info file from the extracted distfile.
WBM_VERSION=	1.270

DEPENDS+=	wbm-apache>=1.270:../../sysutils/wbm-apache
DEPENDS+=	wbm-useradmin>=1.270:../../sysutils/wbm-useradmin

HOMEPAGE=	http://www.webmin.com/standard.html
COMMENT=	Webmin module to protect Apache web-accessible directories

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
