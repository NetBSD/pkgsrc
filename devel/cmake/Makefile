# $NetBSD: Makefile,v 1.11 2004/02/10 02:44:24 jlam Exp $

DISTNAME=	cmake-1.6.6
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cmake.org/
COMMENT=	cross platform make

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_BUILDLINK3=	yes
USE_NCURSES=	yes
USE_GNU_TOOLS+=	make

post-patch:
	for file in ${WRKSRC}/Modules/FindCurses.cmake; do		\
		${MV} -f $$file $$file.bak;				\
		${SED} "s|@prefix@|${PREFIX}|g" $$file.bak > $$file;	\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
