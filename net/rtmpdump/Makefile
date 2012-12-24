# $NetBSD: Makefile,v 1.6 2012/12/24 14:29:24 ryoon Exp $
#

DISTNAME=	rtmpdump-2.4
CATEGORIES=	net multimedia
MASTER_SITES=	http://rtmpdump.mplayerhq.hu/download/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://rtmpdump.mplayerhq.hu/
COMMENT=	Tools for handling RTMP stream
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LIBTOOL=	yes

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
BUILD_DIRS=	. librtmp

WRKSRC=		${WRKDIR}/rtmpdump
PKGCONFIG_OVERRIDE+=	librtmp/librtmp.pc.in

LDFLAGS.SunOS+=	-lnsl -lsocket

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		Makefile
SUBST_FILES.fix-paths+=		librtmp/Makefile
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
