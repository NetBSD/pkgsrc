# $NetBSD: Makefile,v 1.11 2015/01/24 23:23:48 adam Exp $

DISTNAME=	psutil-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	https://pypi.python.org/packages/source/p/psutil/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/psutil/
COMMENT=	Cross-platform process and system utilities module for Python
LICENSE=	modified-bsd

REPLACE_PYTHON=	psutil/*py

.include "../../mk/bsd.prefs.mk"

# facilitate PLIST processing
.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	SYSTEM=osx
.else
PLIST_SUBST+=	SYSTEM=${OPSYS:tl}
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
