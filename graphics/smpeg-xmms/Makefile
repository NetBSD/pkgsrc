# $NetBSD: Makefile,v 1.8 2004/03/12 05:25:41 snj Exp $
#

DISTNAME=	smpeg-xmms-0.3.5
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.xmms.org/xmms/plugins/smpeg-xmms/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xmms.org/
COMMENT=	MPEG video plugin using SDL/smpeg as the backend

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

.include "../../devel/smpeg/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
