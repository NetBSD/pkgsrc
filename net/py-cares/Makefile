# $NetBSD: Makefile,v 1.11 2024/05/09 23:20:27 gdt Exp $

DISTNAME=	pycares-4.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycares/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/saghul/pycares
COMMENT=	Python interface for c-ares
LICENSE=	mit

# This package builds but fails to work on NetBSD 9 because NetBSD
# declares structs as __packed, pycares does not, and cffi insists on
# matching alignment.  Details at:
#   https://mail-index.netbsd.org/tech-pkg/2024/05/05/msg029208.html
# \todo One of
#    Pull up 1.112 of src/sys/netinet/in.h to netbsd-9.
#    Fix py-cares or cffi to work with a packed definition.

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.5.0:../../devel/py-cffi

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
