# $NetBSD: Makefile,v 1.2 2004/01/20 12:14:41 agc Exp $

DISTNAME=		VisualBoyAdvance-src-1.6a
PKGNAME=		vba-1.6.0.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vba/}
EXTRACT_SUFX=		.zip

MAINTAINER=		snj@pobox.com
HOMEPAGE=		http://vboy.emuhq.com/
COMMENT=		Gameboy advance emulator

WRKSRC=			${WRKDIR}/VisualBoyAdvance-1.6a
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-c-core
CONFIGURE_ARGS+=	--without-mmx

GCC_REQD=		3.0.0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/TestEmu ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/VisualBoyAdvance ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vba
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/vba

.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
