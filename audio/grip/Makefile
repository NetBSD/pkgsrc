# $NetBSD: Makefile,v 1.33 2020/11/12 10:03:18 triaxx Exp $

DISTNAME=	grip-4.2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=grip/}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/grip/
COMMENT=	CD-player and CD-ripper for the Gnome desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

.include "../../audio/grip/options.mk"

CONFIGURE_ARGS+=	--disable-werror

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
