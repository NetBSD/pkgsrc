# $NetBSD: Makefile,v 1.13 2014/05/09 07:37:15 wiz Exp $

DISTNAME=	libdnet-1.12
PKGNAME=	${PYPKGPREFIX}-libdnet-1.12
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	http://libdnet.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libdnet/
COMMENT=	Python wrapper for libdnet
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
PYSETUPSUBDIR=	python
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.12

EGG_NAME=	${DISTNAME:S/^lib//}

.include "../../lang/python/distutils.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
