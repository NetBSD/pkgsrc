# $NetBSD: Makefile,v 1.12 2012/10/03 12:55:17 asau Exp $
#

DISTNAME=		sms_sdl-0.9.4a-r7.1-src
PKGNAME=		sms_sdl-0.9.4a.7.1
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		http://membres.multimania.fr/cyxdown/smssdl/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://membres.multimania.fr/cyxdown/smssdl/
COMMENT=		SMS Plus emulator port to SDL

WRKSRC=			${WRKDIR}/sms_sdl-0.9.4a-r7.1
BUILD_DIRS=		sdl

INSTALLATION_DIRS=	bin

LDFLAGS.DragonFly=	-lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdl/sms_sdl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/sms_sdl
	${INSTALL_DATA} ${WRKSRC}/sdl/README.TXT \
		${DESTDIR}${PREFIX}/share/doc/sms_sdl
	${INSTALL_DATA} ${WRKSRC}/license ${DESTDIR}${PREFIX}/share/doc/sms_sdl
	${INSTALL_DATA} ${WRKSRC}/README.TXT \
		${DESTDIR}${PREFIX}/share/doc/sms_sdl/README-CORE.TXT
	${INSTALL_DATA} ${WRKSRC}/SOURCE.TXT \
		${DESTDIR}${PREFIX}/share/doc/sms_sdl

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
