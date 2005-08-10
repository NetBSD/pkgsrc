# $NetBSD: Makefile,v 1.1.1.1 2005/08/10 13:52:52 drochner Exp $
#

DISTNAME=	libdnet-1.10
PKGNAME=	${PYPKGPREFIX}-libdnet-1.10
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdnet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libdnet.sourceforge.net/
COMMENT=	Python wrapper for libdnet

GNU_CONFIGURE=	yes
PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	python

.include "../../lang/python/extension.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
