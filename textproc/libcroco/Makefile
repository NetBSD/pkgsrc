# $NetBSD: Makefile,v 1.29 2006/11/05 17:06:43 joerg Exp $
#

DISTNAME=	libcroco-0.6.1
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libcroco/0.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freespiders.org/projects/libcroco/
COMMENT=	Toolkit to parse and manipulate CSS (Cascading Style Sheets)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    libcroco-0.6.pc

CONFIGURE_ARGS+=	--enable-seleng=yes
CONFIGURE_ARGS+=	--enable-layeng=yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
