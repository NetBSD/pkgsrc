# $NetBSD: Makefile,v 1.7 2006/06/12 16:28:07 wiz Exp $
#

DISTNAME=		sms_sdl-0.9.4a-r7.1-src
PKGNAME=		sms_sdl-0.9.4a.7.1
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		http://membres.lycos.fr/cyxdown/smssdl/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://membres.lycos.fr/cyxdown/smssdl/
COMMENT=		SMS Plus emulator port to SDL

WRKSRC=			${WRKDIR}/sms_sdl-0.9.4a-r7.1
BUILD_DIRS=		sdl
EXTRACT_OPTS_ZIP=	-aqo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdl/sms_sdl ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sms_sdl
	${INSTALL_DATA} ${WRKSRC}/sdl/README.TXT ${PREFIX}/share/doc/sms_sdl
	${INSTALL_DATA} ${WRKSRC}/license ${PREFIX}/share/doc/sms_sdl
	${INSTALL_DATA} ${WRKSRC}/README.TXT \
		${PREFIX}/share/doc/sms_sdl/README-CORE.TXT
	${INSTALL_DATA} ${WRKSRC}/SOURCE.TXT ${PREFIX}/share/doc/sms_sdl

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
