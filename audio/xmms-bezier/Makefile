# $NetBSD: Makefile,v 1.4 2003/05/02 11:53:48 wiz Exp $
#

DISTNAME=	bezier-0.0.3
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://yossman.net/~kuroyi/

MAINTAINER=	hubertf@netbsd.org
COMMENT=	OpenGL XMMS plugin

GNU_CONFIGURE=	yes
USE_X11=	yes
CPPFLAGS+=	-I${X11BASE}/include -I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
USE_LIBTOOL=	yes
USE_BUILDLINK2= yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

pre-configure:
		cd ${WRKSRC} ; ${MV} configure configure.BAK ; \
		${SED} \
			-e 's,-lMesaGL,-lGL -L${X11BASE}/lib -lX11 -lXext -lm,' \
			<configure.BAK >configure ; \
		${CHMOD} +x configure

.include "../../audio/xmms/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
