# $NetBSD: Makefile,v 1.8 2009/03/05 18:51:31 joerg Exp $
#

DISTNAME=	pycrack-0.01
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/py//}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://www.digitalevacuation.org/pycrack/

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.digitalevacuation.org/
COMMENT=	Python interface to cracklib

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=			crack>=5.0:../../security/crack

MAKE_ENV+=			MANDIR=${LOCALBASE}/man
MAKE_ENV+=			BINDIR=${LOCALBASE}/bin
USE_TOOLS+=		gmake

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../security/libcrack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
