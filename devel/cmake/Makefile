# $NetBSD: Makefile,v 1.20 2006/02/05 23:08:40 joerg Exp $

DISTNAME=	cmake-2.0.5
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v2.0/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cmake.org/
COMMENT=	Cross platform make

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_NCURSES=		yes
GNU_CONFIGURE=		yes
CONFIGURE_HAS_MANDIR=	no
CONFIGURE_ARGS+=	--mandir=/${PKGMANDIR}
BUILD_TARGET=		default_target

post-extract:
	${CP} ${WRKSRC}/Modules/Platform/FreeBSD.cmake \
		${WRKSRC}/Modules/Platform/DragonFly.cmake

post-patch:
	for file in ${WRKSRC}/Modules/FindCurses.cmake; do		\
		${MV} -f $$file $$file.bak;				\
		${SED} "s|@prefix@|${PREFIX}|g" $$file.bak > $$file;	\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
