# $NetBSD: Makefile,v 1.8 2008/04/25 20:39:08 joerg Exp $
#

DISTNAME=		Cheetah-2.0
PKGNAME=		${PYPKGPREFIX}-cheetah-2.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cheetahtemplate/}

CONFLICTS=		Cheetah-[0-9]*

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://cheetahtemplate.sourceforge.net/
COMMENT=		Python-powered template engine and code-generator

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes
PYSETUP=		setup.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
