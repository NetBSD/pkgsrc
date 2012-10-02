# $NetBSD: Makefile,v 1.6 2012/10/02 23:48:16 asau Exp $
#

DISTNAME=	xmms-nas-0.2
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/willem/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	ftp://ftp.stack.nl/pub/users/willem/
COMMENT=	XMMS output plugin for Network Audio System (NAS)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../audio/nas/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
