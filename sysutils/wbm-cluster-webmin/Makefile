# $NetBSD: Makefile,v 1.1.1.1 2006/05/16 21:40:45 jlam Exp $

DISTNAME=	cluster-webmin
PKGNAME=	wbm-${DISTNAME}-${WBM_VERSION}
DIST_SUBDIR=	webmin-modules-${WBM_VERSION}

# The version is from the module.info file from the extracted distfile.
WBM_VERSION=	1.270

HOMEPAGE=	http://www.webmin.com/standard.html
COMMENT=	Webmin module to manage Webmin settings across a Webmin cluster

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
