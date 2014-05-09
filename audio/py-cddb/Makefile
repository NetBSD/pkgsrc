# $NetBSD: Makefile,v 1.18 2014/05/09 07:36:54 wiz Exp $

DISTNAME=	CDDB-1.4
PKGNAME=	${PYPKGPREFIX}-cddb-1.4
PKGREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cddb-py/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://cddb-py.sourceforge.net/
COMMENT=	Python module to access the CDDB online database
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.4

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
