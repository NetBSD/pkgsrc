# $NetBSD: Makefile,v 1.14 2006/02/05 23:09:15 joerg Exp $
#

DISTNAME=	glchess-0.4.7
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glchess/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://glchess.sourceforge.net/
COMMENT=	3D chess interface

USE_TOOLS+=	automake
GNU_CONFIGURE=	YES
INSTALL_DIRS=	${WRKSRC}/src ${WRKSRC}/man ${WRKSRC}/textures

pre-configure:
		cd ${WRKSRC} &&						\
		aclocal &&						\
		automake --add-missing &&				\
		autoconf &&						\
		${CP} glchessrc glchessrc.dist &&			\
		${SED}	-e 's|/usr/local/share/games|${PREFIX}/share|g'	\
			 < glchessrc.dist > glchessrc &&		\
		${CP} src/config.c src/config.c.dist &&			\
		${SED}	-e 's|/etc|${PKG_SYSCONFDIR}|g'			\
			-e 's|@PKGETC@|${PREFIX}/etc|g'			\
			< src/config.c.dist > src/config.c

post-install:
		${INSTALL_DATA} ${WRKSRC}/glchessrc			\
			${PREFIX}/etc/glchessrc.default

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
