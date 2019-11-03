# $NetBSD: Makefile,v 1.7 2019/11/03 10:18:28 rillig Exp $

DISTNAME=	PyODE-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//:tl}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyODE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyode.sourceforge.net/
COMMENT=	Python wrapper for the Open Dynamics Engine
LICENSE=	modified-bsd OR gnu-lgpl-v2.1

PYTHON_VERSIONS_ACCEPTED=	27 # as of 1.2.1

.include "../../devel/ode/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
