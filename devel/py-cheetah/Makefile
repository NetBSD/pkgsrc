# $NetBSD: Makefile,v 1.9 2008/04/29 11:07:36 shannonjr Exp $
#

DISTNAME=		Cheetah-2.0.1
PKGNAME=		${PYPKGPREFIX}-cheetah-2.0.1
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
