# $NetBSD: Makefile,v 1.10 2005/12/05 20:49:53 rillig Exp $

DISTNAME=	kadu-0.4.1
CATEGORIES=	chat
MASTER_SITES=	http://www.kadu.net/download/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.kadu.net/
COMMENT=	Chat client for Gadu-Gadu network (Poland)

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-existing-libgadu=${BUILDLINK_PREFIX.ekg}
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}
LIBS+=			${LIBOSSAUDIO}
WRKSRC=			${WRKDIR}/kadu

# pure hack
post-configure:
	cd ${WRKSRC}; ${TOUCH} Makefile

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../chat/ekg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
