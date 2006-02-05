# $NetBSD: Makefile,v 1.14 2006/02/05 23:08:17 joerg Exp $
#

DISTNAME=	bezier-0.0.3
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://yossman.net/~kuroyi/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	OpenGL XMMS plugin

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1
LIBS+=		-lX11 -lm

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
