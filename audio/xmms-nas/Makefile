# $NetBSD: Makefile,v 1.8 2016/04/20 12:10:35 nros Exp $
#

DISTNAME=	xmms-nas-0.2
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/willem/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	ftp://ftp.stack.nl/pub/users/willem/
COMMENT=	XMMS output plugin for Network Audio System (NAS)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../audio/nas/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
