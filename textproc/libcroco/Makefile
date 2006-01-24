# $NetBSD: Makefile,v 1.22 2006/01/24 07:32:37 wiz Exp $
#

DISTNAME=	libcroco-0.6.0
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libcroco/0.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.freespiders.org/projects/libcroco/
COMMENT=	Toolkit to parse and manipulate CSS (Cascading Style Sheets)

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    libcroco-0.6.pc.in

CONFIGURE_ARGS+=	--enable-seleng=yes
CONFIGURE_ARGS+=	--enable-layeng=yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
