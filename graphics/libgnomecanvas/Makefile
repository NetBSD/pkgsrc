# $NetBSD: Makefile,v 1.1.1.1 2002/09/07 04:41:42 rh Exp $
#

DISTNAME=	libgnomecanvas-2.0.4
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=2.0.1/sources/libgnomecanvas/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME Canvas library

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_GNU_GETTEXT=	yes
USE_X11BASE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
