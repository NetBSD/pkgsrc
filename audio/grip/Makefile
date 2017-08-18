# $NetBSD: Makefile,v 1.1 2017/08/18 12:21:29 triaxx Exp $

DISTNAME=	grip-3.5.2
CATEGORIES=	audio
MASTER_SITES=	https://downloads.sourceforge.net/project/grip/3.5.2/

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://sourceforge.net/project/grip/
COMMENT=	CD-player and CD-ripper for the Gnome desktop
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../audio/grip/options.mk"

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
