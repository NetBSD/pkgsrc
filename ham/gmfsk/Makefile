# $NetBSD: Makefile,v 1.16 2006/05/25 18:16:27 wiz Exp $
#

DISTNAME=	gmfsk-0.6
PKGREVISION=	7
CATEGORIES=	ham
MASTER_SITES=	http://gmfsk.connect.fi/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://gmfsk.connect.fi/
COMMENT=	Multimode HF terminal program

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
GCONF2_SCHEMAS+=gmfsk.schemas

CONFIGURE_ARGS+=--enable-hamlib

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../math/fftw2/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../textproc/scrollkeeper/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
