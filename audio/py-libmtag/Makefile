# $NetBSD: Makefile,v 1.2 2009/07/08 16:02:05 drochner Exp $
#

DISTNAME=	libmtag-python-0.3.0
PKGNAME=	${PYPKGPREFIX}-libmtag-0.3.0
CATEGORIES=	audio
MASTER_SITES=	http://libmtag.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libmtag/
COMMENT=	Python binding for libmtag

USE_TOOLS+=	pkg-config
PYDISTUTILSPKG=	yes
PKG_DESTDIR_SUPPORT= user-destdir

.include "../../lang/python/extension.mk"
.include "../../audio/libmtag/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
