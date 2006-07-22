# $NetBSD: Makefile,v 1.14 2006/07/22 04:46:15 rillig Exp $
#

DISTNAME=	fastdep-0.16
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.irule.be/bvh/c++/fastdep/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.irule.be/bvh/c++/fastdep/
COMMENT=	Dependency generator for C/C++ files

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

post-extract:
	${RM} -f ${WRKSRC}/*.orig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastdep ${PREFIX}/bin/fastdep

.include "../../mk/bsd.pkg.mk"
