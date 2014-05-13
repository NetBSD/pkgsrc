# $NetBSD: Makefile,v 1.33 2014/05/13 17:09:21 joerg Exp $

DISTNAME=	rpy2-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/rpy2/rpy/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rpy.sourceforge.net/
COMMENT=	R interface for Python
LICENSE=	mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1

USE_LANGUAGES+=		c fortran77

BUILDLINK_API_DEPENDS.R+= R>=2.11.0

LDFLAGS.SunOS+=		-mimpure-text

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
