# $NetBSD: Makefile,v 1.5 2016/07/09 13:03:48 wiz Exp $

DISTNAME=		vatnumber-1.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		finance python
MASTER_SITES=		http://vatnumber.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://code.google.com/p/vatnumber/
COMMENT=		Python module to validate VAT numbers
LICENSE=		gnu-gpl-v3

PKG_OPTIONS_VAR=        PKG_OPTIONS.py-vatnumber
PKG_SUPPORTED_OPTIONS=  vatnumber-suds
PKG_SUGGESTED_OPTIONS=  vatnumber-suds

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mvatnumber-suds)
DEPENDS+=		${PYPKGPREFIX}-suds-[0-9]*:../../net/py-suds
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-suds
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
