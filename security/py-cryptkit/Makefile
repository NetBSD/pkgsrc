# $NetBSD: Makefile,v 1.12 2008/05/08 18:33:53 joerg Exp $

DISTNAME=	cryptkit-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cryptkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cryptkit.sourceforge.net/
COMMENT=	Python Cryptographic Toolkit

PKG_DESTDIR_SUPPORT=	user-destdir

PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
