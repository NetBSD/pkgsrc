# $NetBSD: Makefile,v 1.15 2009/03/21 05:46:54 obache Exp $
#

DISTNAME=	tokyotyrant-1.1.18
CATEGORIES=	databases net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/
COMMENT=	Network interface of Tokyo Cabinet

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	tokyotyrant.pc.in

TEST_TARGET=	check

.include "options.mk"

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.10
.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
