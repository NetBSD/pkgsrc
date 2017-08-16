# $NetBSD: Makefile,v 1.17 2017/08/16 21:22:14 wiz Exp $

DISTNAME=	libdnet-1.12
PKGNAME=	${PYPKGPREFIX}-libdnet-1.12
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	http://libdnet.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dugsong/libdnet
COMMENT=	Python wrapper for libdnet
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
PYSETUPSUBDIR=	python
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 1.12

EGG_NAME=	${DISTNAME:S/^lib//}

.include "../../lang/python/distutils.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
