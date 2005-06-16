# $NetBSD: Makefile,v 1.11 2005/06/16 06:57:51 jlam Exp $

DISTNAME=		VisualBoyAdvance-src-1.6a
PKGNAME=		vba-1.6.0.1
PKGREVISION=	2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vba/}
EXTRACT_SUFX=		.zip

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://vboy.emuhq.com/
COMMENT=		Gameboy advance emulator

WRKSRC=			${WRKDIR}/VisualBoyAdvance-1.6a
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-c-core
CONFIGURE_ARGS+=	--without-mmx
USE_LANGUAGES=		c c++

GCC_REQD+=		3.0.0
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/TestEmu ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/VisualBoyAdvance ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vba
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/vba

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
