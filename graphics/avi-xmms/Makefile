# $NetBSD: Makefile,v 1.8 2004/01/26 15:16:53 jmmv Exp $
#

DISTNAME=	avi-xmms-1.2.2
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.xmms.org/files/plugins/avi-xmms/ \
		ftp://ftp.sunet.se/pub/multimedia/xmms/plugins/avi-xmms/ \
		ftp://ftp.fu-berlin.de/unix/sound/xmms/plugins/avi-xmms/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xmms.org/
COMMENT=	Avifile and SDL based video plugin for XMMS

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../audio/xmms/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../multimedia/avifile/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
