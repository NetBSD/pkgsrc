# $NetBSD: Makefile,v 1.19 2009/05/24 12:42:44 obache Exp $
#

DISTNAME=	tokyotyrant-1.1.27
CATEGORIES=	databases net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/
COMMENT=	Network interface of Tokyo Cabinet
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	tokyotyrant.pc.in

TEST_TARGET=	check

.include "options.mk"

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.21
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
