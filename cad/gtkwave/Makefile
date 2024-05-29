# $NetBSD: Makefile,v 1.132 2024/05/29 16:31:27 adam Exp $
#

DISTNAME=		gtkwave-3.3.115
PKGREVISION=		6
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkwave/}
#MASTER_SITES=		http://home.nc.rr.com/gtkwave/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gtkwave.sourceforge.net/
COMMENT=		Electronic waveform viewer
LICENSE=		gnu-gpl-v3

TOOL_DEPENDS+=		gperf-[0-9]*:../../devel/gperf

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES+=		c c++

PTHREAD_AUTO_VARS=		yes
CHECK_PORTABILITY_SKIP+=	contrib/bundle_for_osx/*.sh

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtkwave
PKG_SUPPORTED_OPTIONS=	gtkwave-tcl gconf
PKG_SUGGESTED_OPTIONS=	gconf
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtkwave-tcl)
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if !empty(PKG_OPTIONS:Mgconf)
CONFIGURE_ARGS+=	--with-gconf
.include "../../devel/gconfmm/buildlink3.mk"
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
