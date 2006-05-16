# $NetBSD: Makefile,v 1.1.1.1 2006/05/16 21:40:03 jlam Exp $

DISTNAME=	cluster-passwd
PKGNAME=	wbm-${DISTNAME}-${WBM_VERSION}
DIST_SUBDIR=	webmin-modules-${WBM_VERSION}

# The version is from the module.info file from the extracted distfile.
WBM_VERSION=	1.270

DEPENDS+=	wbm-cluster-useradmin>=1.270:../../sysutils/wbm-cluster-useradmin

HOMEPAGE=	http://www.webmin.com/standard.html
COMMENT=	Webmin module to change users' passwords within a Webmin cluster

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
