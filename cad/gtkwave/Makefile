# $NetBSD: Makefile,v 1.43 2012/10/02 17:10:38 tron Exp $
#

DISTNAME=		gtkwave-3.3.28
PKGREVISION=		6
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkwave/}
#MASTER_SITES=		http://home.nc.rr.com/gtkwave/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gtkwave.sourceforge.net/
COMMENT=		Electronic waveform viewer

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		gperf-[0-9]*:../../devel/gperf

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tcl
USE_TOOLS+=		gmake pkg-config

PTHREAD_AUTO_VARS=	yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
