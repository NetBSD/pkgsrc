# $NetBSD: Makefile,v 1.4 2014/01/25 10:30:22 wiz Exp $

DISTNAME=	psutil-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	https://pypi.python.org/packages/source/p/psutil/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/psutil/
COMMENT=	Cross-platform process and system utilities module for Python
LICENSE=	modified-bsd

REPLACE_PYTHON=	psutil/*py
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 1.2.1

.include "../../mk/bsd.prefs.mk"

# facilitate PLIST processing
.if ${OPSYS} == "SunOS"
LOWER_OPSYS=	${OPSYS:tl}
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
