# $NetBSD: Makefile,v 1.149 2026/03/18 07:00:47 adam Exp $

DISTNAME=	gtkwave-3.3.125
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkwave/}
#MASTER_SITES=	http://home.nc.rr.com/gtkwave/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gtkwave.sourceforge.net/
COMMENT=	Electronic waveform viewer
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

PTHREAD_AUTO_VARS=		yes
CHECK_PORTABILITY_SKIP+=	contrib/bundle_for_osx/*.sh

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
.include "../../x11/gtk-mac-integration/buildlink3.mk"
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
