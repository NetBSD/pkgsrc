# $NetBSD: Makefile,v 1.1.1.1 2001/08/16 01:35:13 hubertf Exp $
#

DISTNAME=	dflowers_v1.0
PKGNAME=	xmms-dflowers-1.0
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual flower scope

DEPENDS+=	xmms>=1.2.5:../../audio/xmms

USE_X11=	yes
#CPPFLAGS+=	-I${X11BASE}/include
#CFLAGS+=	-I${LOCALBASE}/include
USE_LIBTOOL=	yes
#CPPFLAGS+=		-D_POSIX_THREAD_SYSCALL_SOFT=1

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
