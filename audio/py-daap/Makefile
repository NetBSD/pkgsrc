# $NetBSD: Makefile,v 1.15 2018/07/03 05:03:02 adam Exp $

DISTNAME=	PythonDaap-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PythonD/d/}
PKGREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://jerakeen.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://movieos.org/code/pythondaap/
COMMENT=	Python binding for DAAP
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.7
CONFLICTS=	${PYPKGPREFIX}-PythonDaap-[0-9]*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
