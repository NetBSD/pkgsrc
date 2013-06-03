# $NetBSD: Makefile,v 1.47 2013/06/03 10:04:37 wiz Exp $
#

DISTNAME=		gtkwave-3.3.28
PKGREVISION=		9
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkwave/}
#MASTER_SITES=		http://home.nc.rr.com/gtkwave/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gtkwave.sourceforge.net/
COMMENT=		Electronic waveform viewer

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
