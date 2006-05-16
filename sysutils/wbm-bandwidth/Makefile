# $NetBSD: Makefile,v 1.1.1.1 2006/05/16 15:39:59 jlam Exp $

DISTNAME=	bandwidth
PKGNAME=	wbm-${DISTNAME}-${WBM_VERSION}
DIST_SUBDIR=	webmin-modules-${WBM_VERSION}

# The version is from the module.info file from the extracted distfile.
WBM_VERSION=	1.270

DEPENDS+=	wbm-net>=1.270:../../sysutils/wbm-net

HOMEPAGE=	http://www.webmin.com/standard.html
COMMENT=	Webmin module to view bandwidth usage

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
