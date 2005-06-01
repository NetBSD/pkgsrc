# $NetBSD: Makefile,v 1.17 2005/06/01 18:02:47 jlam Exp $

DISTNAME=	hatari-0.60
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hatari/}

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://hatari.sourceforge.net/
COMMENT=	Atari ST emulator

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hatari
	cd ${WRKSRC} && ${INSTALL_DATA} *.txt ${PREFIX}/share/doc/hatari
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.txt *.html \
			${PREFIX}/share/doc/hatari

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
