# $NetBSD: Makefile,v 1.24 2019/04/26 13:13:42 maya Exp $

DISTNAME=	CDDB-1.4
PKGNAME=	${PYPKGPREFIX}-cddb-1.4
PKGREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cddb-py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cddb-py.sourceforge.net/
COMMENT=	Python module to access the CDDB online database
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 1.4

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
