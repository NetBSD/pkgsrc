# $NetBSD: Makefile,v 1.14 2018/07/03 05:03:29 adam Exp $

DISTNAME=	omniORBpy-3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omniorb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://omniorb.sourceforge.net/
COMMENT=	Python interface to omniORB

PLIST_SUBST+=	PYINC=${PYINC} PYSITELIB=${PYSITELIB}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++
MAKE_FILE=	GNUmakefile

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # omniORB

.include "../../lang/python/application.mk"
.include "../../net/omniORB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
