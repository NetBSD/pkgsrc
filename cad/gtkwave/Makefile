# $NetBSD: Makefile,v 1.52 2014/01/19 09:25:17 mef Exp $
#

DISTNAME=		gtkwave-3.3.53
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkwave/}
#MASTER_SITES=		http://home.nc.rr.com/gtkwave/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gtkwave.sourceforge.net/
COMMENT=		Electronic waveform viewer
LICENSE=		gnu-gpl-v3

BUILD_DEPENDS+=		gperf-[0-9]*:../../devel/gperf

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tcl
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES+=		c c++

PTHREAD_AUTO_VARS=	yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
