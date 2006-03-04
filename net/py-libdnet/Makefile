# $NetBSD: Makefile,v 1.3 2006/03/04 21:30:23 jlam Exp $
#

DISTNAME=	libdnet-1.10
PKGNAME=	${PYPKGPREFIX}-libdnet-1.10
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdnet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libdnet.sourceforge.net/
COMMENT=	Python wrapper for libdnet

GNU_CONFIGURE=	yes
PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	python

.include "../../lang/python/extension.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
