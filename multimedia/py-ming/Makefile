# $NetBSD: Makefile,v 1.9 2010/06/13 22:45:06 wiz Exp $
#

.include "../../multimedia/ming/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		multimedia

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://ming.sourceforge.net/
COMMENT=		Python bindings for Ming library
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes

PYSETUPSUBDIR=		py_ext

PYDISTUTILSPKG=		yes

.include "../../multimedia/ming/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
