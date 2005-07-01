# $NetBSD: Makefile,v 1.18 2005/07/01 09:35:38 adam Exp $

DISTNAME=	hatari-0.70
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hatari/}

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://hatari.sourceforge.net/
COMMENT=	Atari ST emulator

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hatari
	cd ${WRKSRC} && ${INSTALL_DATA} *.txt ${PREFIX}/share/doc/hatari
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.txt *.html \
			${PREFIX}/share/doc/hatari

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
