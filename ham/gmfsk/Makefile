# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:41 joerg Exp $
#

DISTNAME=	gmfsk-0.6
PKGREVISION=	3
CATEGORIES=	ham
MASTER_SITES=	http://gmfsk.connect.fi/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://gmfsk.connect.fi/
COMMENT=	Multimode HF terminal program

USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
GCONF2_SCHEMAS+=gmfsk.schemas

CONFIGURE_ARGS+=--enable-hamlib

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../textproc/scrollkeeper/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
