# $NetBSD: Makefile,v 1.3 2020/06/03 13:47:21 nia Exp $

.include "Makefile.common"

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://sameboy.github.io/
COMMENT=	Highly accurate Game Boy and Game Boy Color emulator

BUILD_TARGET=	sdl

MAKE_FLAGS+=	DATA_DIR=${PREFIX}/share/sameboy/

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/sameboy
INSTALLATION_DIRS+=	share/sameboy
INSTALLATION_DIRS+=	share/sameboy/Shaders

BUILDLINK_TRANSFORM+=	rm:-Werror

do-install:
	cd ${WRKSRC}/build/bin/SDL && ${INSTALL_PROGRAM} sameboy \
	    ${DESTDIR}${PREFIX}/bin/sameboy
	cd ${WRKSRC}/build/bin/SDL && ${INSTALL_DATA} *.bin *.sym *.bmp \
	    ${DESTDIR}${PREFIX}/share/sameboy
	cd ${WRKSRC}/build/bin/SDL && ${INSTALL_DATA} LICENSE \
	    ${DESTDIR}${PREFIX}/share/doc/sameboy
	cd ${WRKSRC}/build/bin/SDL/Shaders && ${INSTALL_DATA} *.fsh \
	    ${DESTDIR}${PREFIX}/share/sameboy/Shaders

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
