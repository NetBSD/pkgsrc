# $NetBSD: Makefile,v 1.17 2023/12/22 18:31:14 zafer Exp $
#

DISTNAME=		wbd-1.0ucl4
PKGNAME=		wbd-1.0p4
PKGREVISION=		11
CATEGORIES=		mbone tk
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-mice.cs.ucl.ac.uk/multimedia/software/wbd/
COMMENT=		Multicast WhiteBoarD

MAKE_FILE=		makefile
WRKSRC=			${WRKDIR}/wbd
BUILD_TARGET=		wbd
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"
CFLAGS+=	-DUSE_INTERP_RESULT
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

LDFLAGS.SunOS+=		-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wbd ${DESTDIR}${PREFIX}/bin/wbd

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
