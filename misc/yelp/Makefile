# $NetBSD: Makefile,v 1.10 2004/02/11 07:43:22 xtraeme Exp $
#

DISTNAME=		yelp-2.4.2
PKGREVISION=		5
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/yelp/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Help browser for GNOME 2 desktop

DEPENDS=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-html-widget=gtkhtml2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/libgtkhtml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
