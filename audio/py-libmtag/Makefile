# $NetBSD: Makefile,v 1.3 2011/10/15 10:37:18 obache Exp $
#

DISTNAME=	libmtag-python-0.3.0
PKGNAME=	${PYPKGPREFIX}-libmtag-0.3.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://libmtag.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libmtag/
COMMENT=	Python binding for libmtag

PKG_DESTDIR_SUPPORT= user-destdir

USE_TOOLS+=	pkg-config

EGG_NAME=	MTag-0.0.0

.include "../../lang/python/distutils.mk"
.include "../../audio/libmtag/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
