# $NetBSD: Makefile,v 1.3 2007/02/19 21:52:42 joerg Exp $

DISTNAME=	postfix
PKGNAME=	wbm-${DISTNAME}-${WBM_VERSION}
PKGREVSION=	1
DIST_SUBDIR=	webmin-modules-${WBM_VERSION}

# The version is from the module.info file from the extracted distfile.
WBM_VERSION=	1.270

HOMEPAGE=	http://www.webmin.com/standard.html
COMMENT=	Webmin module for Postfix mail server configuration

BROKEN=		"Distfile broken"

.include "../../sysutils/webmin/wbm.mk"
.include "../../mk/bsd.pkg.mk"
