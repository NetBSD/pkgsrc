# $NetBSD: Makefile,v 1.23 2019/04/26 14:12:43 maya Exp $

DISTNAME=	adns-python-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	http://adns-python.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/adns-python/
COMMENT=	Python interface to the GNU asynchronous DNS resolver library
LICENSE=	gnu-gpl-v2

CONFLICTS=	${PYPKGPREFIX}-adns-python-[0-9]*

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 1.2.1

BUILDLINK_API_DEPENDS.adns+=	adns>=1.2
.include "../../net/adns/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
