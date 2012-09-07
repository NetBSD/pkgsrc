# $NetBSD: Makefile,v 1.17 2012/09/07 19:17:00 adam Exp $
#

DISTNAME=	tomoe-gtk-0.6.0
PKGREVISION=	14
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tomoe/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tomoe.sourceforge.jp/
COMMENT=	GUI library for tomoe's GTK+ GUI parts
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	tomoe-gtk.pc.in

CONFIGURE_ARGS+=	--without-python

SUBST_CLASSES+=		gucharmap2
SUBST_STAGE.gucharmap2=	pre-configure
SUBST_FILES.gucharmap2=	configure
SUBST_SED.gucharmap2=	-e 's|gucharmap >= 1.4.0|gucharmap-2|g'

.include "../../inputmethod/tomoe/buildlink3.mk"
.include "../../fonts/gucharmap/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
