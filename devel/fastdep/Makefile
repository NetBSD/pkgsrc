# $NetBSD: Makefile,v 1.2 2003/12/03 13:11:18 jmmv Exp $
#

DISTNAME=	fastdep-0.16
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
