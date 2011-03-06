# $NetBSD: Makefile,v 1.1.1.1 2011/03/06 16:45:08 wiz Exp $
#

DISTNAME=	xmms-nas-0.2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/willem/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	ftp://ftp.stack.nl/pub/users/willem/
COMMENT=	XMMS output plugin for Network Audio System (NAS)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../audio/nas/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
