# $NetBSD: Makefile,v 1.15 2005/01/06 13:07:59 adam Exp $

DISTNAME=	cmake-2.0.5
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v2.0/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cmake.org/
COMMENT=	Cross platform make

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_NCURSES=		yes
GNU_CONFIGURE=		yes
BUILD_TARGET=		default_target

post-patch:
	for file in ${WRKSRC}/Modules/FindCurses.cmake; do		\
		${MV} -f $$file $$file.bak;				\
		${SED} "s|@prefix@|${PREFIX}|g" $$file.bak > $$file;	\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
