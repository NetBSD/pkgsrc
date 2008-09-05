# $NetBSD: Makefile,v 1.1.1.1 2008/09/05 06:33:21 bjs Exp $
#

DISTNAME=	bakefile-0.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bakefile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bakefile.sourceforge.net/
COMMENT=	Cross-platform, cross-compiler native makefiles generator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	15 21
REPLACE_PYTHON=			src/empy/em.py

.include "../../lang/python/application.mk"
.include "../../textproc/py-libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
