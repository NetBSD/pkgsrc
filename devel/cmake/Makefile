# $NetBSD: Makefile,v 1.13 2004/10/03 00:13:25 tv Exp $

DISTNAME=	cmake-2.0.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v2.0/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cmake.org/
COMMENT=	Cross platform make

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_BUILDLINK3=	yes
USE_NCURSES=	yes
USE_GNU_TOOLS+=	make
ALL_TARGET=	default_target

post-patch:
	for file in ${WRKSRC}/Modules/FindCurses.cmake; do		\
		${MV} -f $$file $$file.bak;				\
		${SED} "s|@prefix@|${PREFIX}|g" $$file.bak > $$file;	\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
