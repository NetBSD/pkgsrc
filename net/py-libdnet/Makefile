# $NetBSD: Makefile,v 1.6 2007/03/02 10:52:24 drochner Exp $
#

DISTNAME=	libdnet-1.12
PKGNAME=	${PYPKGPREFIX}-libdnet-1.12
CATEGORIES=	devel net
MASTER_SITES=	http://libdnet.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libdnet/
COMMENT=	Python wrapper for libdnet

GNU_CONFIGURE=	yes
PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	python
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
