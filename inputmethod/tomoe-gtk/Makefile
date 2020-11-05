# $NetBSD: Makefile,v 1.45 2020/11/05 09:06:56 ryoon Exp $
#

DISTNAME=	tomoe-gtk-0.6.0
PKGREVISION=	38
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tomoe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tomoe.osdn.jp/
COMMENT=	GUI library for tomoe's GTK+ GUI parts
LICENSE=	gnu-lgpl-v2.1

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
