# $NetBSD: Makefile,v 1.8 2011/11/01 06:01:03 sbd Exp $
#

DISTNAME=		winpdb-1.4.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		7
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
