# $NetBSD: Makefile,v 1.9 2004/08/02 02:52:47 minskim Exp $
#

DISTNAME=	bezier-0.0.3
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://yossman.net/~kuroyi/

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	OpenGL XMMS plugin

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_LIBTOOL=	yes
USE_BUILDLINK3= yes
CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1
LIBS+=		-lX11 -lm

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
