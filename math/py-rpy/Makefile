# $NetBSD: Makefile,v 1.34 2015/04/07 22:14:18 wiz Exp $

DISTNAME=	rpy2-2.5.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/rpy2/rpy/}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/r/rpy2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rpy.sourceforge.net/
COMMENT=	R interface for Python
LICENSE=	mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1

USE_LANGUAGES+=		c fortran77

BUILDLINK_API_DEPENDS.R+= R>=2.11.0

LDFLAGS.SunOS+=		-mimpure-text

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
