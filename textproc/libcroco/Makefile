# $NetBSD: Makefile,v 1.11 2004/04/01 18:26:22 jmmv Exp $
#

DISTNAME=	libcroco-0.5.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libcroco/0.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.freespiders.org/projects/libcroco/
COMMENT=	Toolkit to parse and manipulate CSS (Cascading Style Sheets)

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    libcroco.pc.in

CONFIGURE_ARGS+=	--enable-seleng=yes
CONFIGURE_ARGS+=	--enable-layeng=yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
