# $NetBSD: Makefile,v 1.32 2012/10/03 00:02:39 asau Exp $

DISTNAME=	kadu-0.5.0
PKGREVISION=	8
CATEGORIES=	chat
MASTER_SITES=	http://www.kadu.net/download/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.kadu.net/
COMMENT=	Chat client for Gadu-Gadu network (Poland)

WRKSRC=			${WRKDIR}/kadu
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake bash:run
REPLACE_BASH+=		varia/scripts/kadu_debug_set
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-existing-libgadu=${BUILDLINK_PREFIX.ekg}
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}
LIBS+=			${LIBOSSAUDIO}

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../chat/ekg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
