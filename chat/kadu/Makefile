# $NetBSD: Makefile,v 1.5 2004/10/03 00:13:15 tv Exp $

DISTNAME=	kadu-0.3.9
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://www.kadu.net/download/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.kadu.net/
COMMENT=	Chat client for Gadu-Gadu network (Poland)

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-existing-libgadu=${BUILDLINK_PREFIX.ekg}
LIBS+=			${LIBOSSAUDIO}
WRKSRC=			${WRKDIR}/kadu

# pure hack
post-configure:
	cd ${WRKSRC}; ${TOUCH} Makefile

.include "../../chat/ekg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
