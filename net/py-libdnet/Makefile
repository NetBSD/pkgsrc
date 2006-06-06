# $NetBSD: Makefile,v 1.4 2006/06/06 20:36:17 joerg Exp $
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
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
