# $NetBSD: Makefile,v 1.26 2005/08/10 20:56:21 jlam Exp $
#

DISTNAME=		aMule-1.2.8
PKGNAME=		${DISTNAME:S/aMule/amule/}
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amule/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tripledes@eslack.org
HOMEPAGE=		http://amule.sourceforge.net/
COMMENT=		Another Emule P2P client

BUILD_USES_MSGFMT=	yes

CONFLICTS=		xmule-[0-9]*

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-wx-config=${LOCALBASE}/bin/wx24-config

LIBS+=			-lm

UNLIMIT_RESOURCES+=	datasize

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/wxGTK24/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
