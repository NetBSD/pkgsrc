# $NetBSD: Makefile,v 1.125 2024/05/16 06:14:35 wiz Exp $

DISTNAME=	streamtuner-0.99.99
PKGREVISION=	84
CATEGORIES=	audio www
MASTER_SITES=	http://savannah.nongnu.org/download/streamtuner/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/streamtuner/
COMMENT=	Stream directory browser
LICENSE=	modified-bsd

TOOL_DEPENDS+=	hicolor-icon-theme-[0-9]*:../../graphics/hicolor-icon-theme

USE_TOOLS+=		gmake msgfmt pkg-config intltool
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	extras/streamtuner.pc.in

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include "options.mk"

BUILDLINK_TRANSFORM.SunOS+=	rm:-lutil

.include "../../mk/omf-scrollkeeper.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
