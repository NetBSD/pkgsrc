# $NetBSD: Makefile,v 1.10 2008/06/12 02:14:28 joerg Exp $
#

DISTNAME=		Cheetah-2.0.1
PKGNAME=		${PYPKGPREFIX}-cheetah-2.0.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cheetahtemplate/}

CONFLICTS=		Cheetah-[0-9]*

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://cheetahtemplate.sourceforge.net/
COMMENT=		Python-powered template engine and code-generator

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes
PYSETUP=		setup.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
