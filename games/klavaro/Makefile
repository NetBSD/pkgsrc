# $NetBSD: Makefile,v 1.43 2023/01/29 21:16:15 ryoon Exp $

DISTNAME=	klavaro-3.13
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://downloads.sourceforge.net/project/klavaro/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://klavaro.sourceforge.io/
COMMENT=	Touch Typing Tutor
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gettext gmake intltool pkg-config

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--export-dynamic

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtkdatabox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
