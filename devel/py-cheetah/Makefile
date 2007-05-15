# $NetBSD: Makefile,v 1.6 2007/05/15 13:04:29 shannonjr Exp $
#

DISTNAME=		Cheetah-2.0rc8
PKGNAME=		${PYPKGPREFIX}-cheetah-2.0rc8
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
