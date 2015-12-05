# $NetBSD: Makefile,v 1.10 2015/12/05 21:25:28 adam Exp $

DISTNAME=	PythonDaap-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PythonD/d/}
PKGREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://jerakeen.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://movieos.org/code/pythondaap/
COMMENT=	Python binding for DAAP

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.7
CONFLICTS=	${PYPKGPREFIX}-PythonDaap-[0-9]*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
