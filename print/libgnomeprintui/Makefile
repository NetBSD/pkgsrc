# $NetBSD: Makefile,v 1.1.1.1 2002/09/12 04:28:27 rh Exp $
#

DISTNAME=		libgnomeprintui-1.116.0
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.1/sources/libgnomeprintui/}

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Graphical library for the GNOME2 Printing Architecture

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_GNU_GETTEXT=	yes
USE_X11BASE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../print/libgnomeprint/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
