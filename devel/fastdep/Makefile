# $NetBSD: Makefile,v 1.1.1.1 2003/08/22 13:47:40 jmmv Exp $
#

DISTNAME=	fastdep-0.15
CATEGORIES=	devel
MASTER_SITES=	http://www.irule.be/bvh/c++/fastdep/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.irule.be/bvh/c++/fastdep/
COMMENT=	Dependancy generator for C/C++ files

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastdep ${PREFIX}/bin/fastdep

.include "../../mk/bsd.pkg.mk"
