# $NetBSD: Makefile,v 1.50 2011/11/01 06:00:41 sbd Exp $
#

DISTNAME=	streamtuner-0.99.99
PKGREVISION=	15
CATEGORIES=	audio www
MASTER_SITES=	http://savannah.nongnu.org/download/streamtuner/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/streamtuner/
COMMENT=	Stream directory browser

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	hicolor-icon-theme-[0-9]*:../../graphics/hicolor-icon-theme

USE_TOOLS+=		gmake msgfmt pkg-config intltool
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	extras/streamtuner.pc.in

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include "options.mk"

.include "../../mk/omf-scrollkeeper.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
