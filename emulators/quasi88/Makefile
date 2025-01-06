# $NetBSD: Makefile,v 1.2 2025/01/06 21:49:07 ktnb Exp $

DISTNAME=	quasi88-0.6.4
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	https://www.eonet.ne.jp/~showtime/quasi88/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.eonet.ne.jp/~showtime/quasi88/
COMMENT=	NEC PC-8801 Emulator
#LICENSE=	modified-bsd AND non-commercial (fmgen)

RESTRICTED=		non-commercial only (fmgen)
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_LANGUAGES+=	c c++
FORCE_CXX_STD=	c++03
USE_TOOLS+=	gmake

MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin

INSTALLATION_DIRS+=	bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
