# $NetBSD: Makefile,v 1.5 2016/03/03 13:22:43 jperkin Exp $

DISTNAME=	klavaro-2.01
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://downloads.sourceforge.net/project/klavaro/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://klavaro.sourceforge.net/
COMMENT=	Touch Typing Tutor
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gettext gmake intltool pkg-config

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtkdatabox/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
