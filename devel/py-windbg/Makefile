# $NetBSD: Makefile,v 1.2 2010/01/18 09:58:47 wiz Exp $
#

DISTNAME=		winpdb-1.4.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=		http://winpdb.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://winpdb.org
COMMENT=		Python GUI debugger

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
