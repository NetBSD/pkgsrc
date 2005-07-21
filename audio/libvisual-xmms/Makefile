# $NetBSD: Makefile,v 1.5 2005/07/21 16:29:43 wiz Exp $
#

DISTNAME=		libvisual-xmms-0.2.0
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://libvisual.sourceforge.net/
COMMENT=		XMMS plugin for libvisual

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../audio/libvisual/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
