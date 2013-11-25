# $NetBSD: Makefile,v 1.32 2013/11/25 12:00:48 wiz Exp $

DISTNAME=	mlt-0.8.6
PKGREVISION=	14
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.sourceforge.net/project/mlt/mlt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mltframework.org/twiki/bin/view/MLT/
COMMENT=	Open source multimedia framework
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-gpl

PKGCONFIG_OVERRIDE+=	mlt-0.8.6/mlt++.pc.in
PKGCONFIG_OVERRIDE+=	mlt-0.8.6/mlt-framework.pc.in

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/sox/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../multimedia/swfdec/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
