# $NetBSD: Makefile,v 1.2 2011/04/22 13:43:02 obache Exp $
#

DISTNAME=	xmms-nas-0.2
PKGREVISION=	1
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
