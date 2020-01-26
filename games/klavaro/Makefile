# $NetBSD: Makefile,v 1.29 2020/01/26 05:26:24 rillig Exp $

DISTNAME=	klavaro-2.01
PKGREVISION=	25
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

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtkdatabox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
