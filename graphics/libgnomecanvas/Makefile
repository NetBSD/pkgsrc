# $NetBSD: Makefile,v 1.3 2002/10/30 04:13:54 rh Exp $
#

DISTNAME=		libgnomecanvas-2.0.4
PKGREVISION=		1
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomecanvas/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Canvas library

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_GNU_GETTEXT=	yes
USE_X11=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libgnomecanvas/libgnomecanvas-2.0.pc.in

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
