# $NetBSD: Makefile,v 1.21 2019/04/26 13:14:01 maya Exp $

DISTNAME=	piddle-1.0.15
PKGREVISION=	3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=piddle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://piddle.sourceforge.net/
COMMENT=	Python Plug In Drawing, Does Little Else

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
