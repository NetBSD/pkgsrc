# $NetBSD: Makefile,v 1.14 2009/01/04 22:32:04 shattered Exp $
#

DISTNAME=		libvisual-xmms-0.2.0
PKGREVISION=		5
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://localhost.nl/~synap/libvisual-wiki/
COMMENT=		XMMS plugin for libvisual

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt

.include "../../audio/libvisual0.2/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
