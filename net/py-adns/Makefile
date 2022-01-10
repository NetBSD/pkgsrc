# $NetBSD: Makefile,v 1.25 2022/01/10 07:52:20 wiz Exp $

DISTNAME=	adns-python-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	http://adns-python.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/adns-python/
COMMENT=	Python interface to the GNU asynchronous DNS resolver library
LICENSE=	gnu-gpl-v2

CONFLICTS=	${PYPKGPREFIX}-adns-python-[0-9]*

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.2.1

BUILDLINK_API_DEPENDS.adns+=	adns>=1.2
.include "../../net/adns/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
