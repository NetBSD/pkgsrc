# $NetBSD: Makefile,v 1.5 2004/02/13 23:37:29 snj Exp $
#

DISTNAME=	fastdep-0.16
CATEGORIES=	devel
MASTER_SITES=	http://www.irule.be/bvh/c++/fastdep/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.irule.be/bvh/c++/fastdep/
COMMENT=	Dependency generator for C/C++ files

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make

post-extract:
	${RM} -f ${WRKSRC}/*.orig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastdep ${PREFIX}/bin/fastdep

.include "../../mk/bsd.pkg.mk"
