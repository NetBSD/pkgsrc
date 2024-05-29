# $NetBSD: Makefile,v 1.53 2024/05/29 16:31:21 adam Exp $

DISTNAME=	grip-4.2.4
PKGREVISION=	6
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

CONFIGURE_ARGS+=	--disable-werror

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
