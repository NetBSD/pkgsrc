# $NetBSD: Makefile,v 1.1.1.1 2002/10/12 06:17:15 rh Exp $
#

DISTNAME=	glchess-0.4.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=glchess/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://glchess.sourceforge.net/
COMMENT=	3D chess interface

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
INSTALL_DIRS=	${WRKSRC}/src ${WRKSRC}/man ${WRKSRC}/textures

pre-configure:
		cd ${WRKSRC} &&						\
		${ACLOCAL} &&						\
		${AUTOMAKE} --add-missing &&				\
		${AUTOCONF} &&						\
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

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../x11/gtkglarea/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
