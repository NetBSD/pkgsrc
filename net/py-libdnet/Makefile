# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:42 joerg Exp $
#

DISTNAME=	libdnet-1.12
PKGNAME=	${PYPKGPREFIX}-libdnet-1.12
CATEGORIES=	devel net
MASTER_SITES=	http://libdnet.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libdnet/
COMMENT=	Python wrapper for libdnet

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	python

.include "../../lang/python/extension.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
