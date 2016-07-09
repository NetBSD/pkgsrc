# $NetBSD: Makefile,v 1.18 2016/07/09 13:03:51 wiz Exp $

DISTNAME=	piddle-1.0.15
PKGREVISION=	3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=piddle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://piddle.sourceforge.net/
COMMENT=	Python Plug In Drawing, Does Little Else

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	34 35

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
