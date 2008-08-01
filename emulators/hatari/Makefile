# $NetBSD: Makefile,v 1.24 2008/08/01 10:04:09 hauke Exp $

DISTNAME=	hatari-1.0.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hatari/}

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://hatari.sourceforge.net/
COMMENT=	Atari ST emulator

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/doc/hatari

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.txt \
			${DESTDIR}${PREFIX}/share/doc/hatari
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.txt *.html \
			${DESTDIR}${PREFIX}/share/doc/hatari

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
