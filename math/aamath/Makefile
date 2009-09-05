# $NetBSD: Makefile,v 1.1.1.1 2009/09/05 17:32:40 asau Exp $
#

DISTNAME=	aamath-0.3
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://fuse.superglue.se/aamath/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://fuse.superglue.se/aamath/
COMMENT=	ASCII art mathematics

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=		${WRKDIR}/aamath
USE_LANGUAGES=	c++
MAKE_JOBS_SAFE=	no

BUILD_TARGET=	aamath

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aamath ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aamath.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
