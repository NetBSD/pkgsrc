# $NetBSD: Makefile,v 1.18 2005/10/24 15:15:25 rillig Exp $

DISTNAME=	cmake-2.0.5
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

post-patch:
	for file in ${WRKSRC}/Modules/FindCurses.cmake; do		\
		${MV} -f $$file $$file.bak;				\
		${SED} "s|@prefix@|${PREFIX}|g" $$file.bak > $$file;	\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
