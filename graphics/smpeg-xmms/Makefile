# $NetBSD: Makefile,v 1.6 2004/01/24 15:46:44 grant Exp $
#

DISTNAME=	smpeg-xmms-0.3.5
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.xmms.org/xmms/plugins/smpeg-xmms/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xmms.org/
COMMENT=	MPEG video plugin using SDL/smpeg as the backend

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/smpeg/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
