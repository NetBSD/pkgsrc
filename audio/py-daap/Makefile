# $NetBSD: Makefile,v 1.11 2016/04/20 12:10:30 nros Exp $

DISTNAME=	PythonDaap-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PythonD/d/}
PKGREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://jerakeen.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://movieos.org/code/pythondaap/
COMMENT=	Python binding for DAAP
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.7
CONFLICTS=	${PYPKGPREFIX}-PythonDaap-[0-9]*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
