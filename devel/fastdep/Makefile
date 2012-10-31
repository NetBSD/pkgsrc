# $NetBSD: Makefile,v 1.16 2012/10/31 11:16:57 asau Exp $
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
	${INSTALL_PROGRAM} ${WRKSRC}/fastdep ${DESTDIR}${PREFIX}/bin/fastdep

.include "../../mk/bsd.pkg.mk"
