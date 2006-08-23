# $NetBSD: Makefile,v 1.5 2006/08/23 17:45:48 shannonjr Exp $
#

DISTNAME=		Cheetah-2.0rc7
PKGNAME=		${PYPKGPREFIX}-cheetah-2.0rc7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cheetahtemplate/}

CONFLICTS=		Cheetah-[0-9]*

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://cheetahtemplate.sourceforge.net/
COMMENT=		Python-powered template engine and code-generator

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes
PYSETUP=		setup.py
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
