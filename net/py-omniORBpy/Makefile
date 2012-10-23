# $NetBSD: Makefile,v 1.7 2012/10/23 17:19:03 asau Exp $

DISTNAME=	omniORBpy-3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omniorb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://omniorb.sourceforge.net/
COMMENT=	Python interface to omniORB

PLIST_SUBST+=	PYINC=${PYINC} PYSITELIB=${PYSITELIB}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++
MAKE_FILE=	GNUmakefile

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/application.mk"
.include "../../net/omniORB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
