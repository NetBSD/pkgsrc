# $NetBSD: Makefile,v 1.2 2003/05/02 11:55:11 wiz Exp $
#

DISTNAME=	avi-xmms-1.2.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.xmms.org/files/plugins/avi-xmms/ \
		ftp://ftp.sunet.se/pub/multimedia/xmms/plugins/avi-xmms/ \
                ftp://ftp.fu-berlin.de/unix/sound/xmms/plugins/avi-xmms/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.xmms.org/
COMMENT=	Avifile and SDL based video plugin for XMMS

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../audio/xmms/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/avifile/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
