# $NetBSD: Makefile,v 1.21 2005/04/11 21:46:44 tv Exp $
#

DISTNAME=		aMule-1.2.8
PKGNAME=		${DISTNAME:S/aMule/amule/}
PKGREVISION=	3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amule/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tripledes@eslack.org
HOMEPAGE=		http://amule.sourceforge.net/
COMMENT=		Another Emule P2P client

BUILD_USES_MSGFMT=	yes

CONFLICTS=		xmule-[0-9]*

USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

LIBS+=			-lm

UNLIMIT_RESOURCES+=	datasize

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
