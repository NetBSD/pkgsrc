# $NetBSD: Makefile,v 1.2 2004/01/24 09:27:43 tron Exp $
#

.include "../../graphics/xine-lib/Makefile.common"

PKGNAME:=	${PKGNAME:S/lib/arts/}
CATEGORIES=	audio

DEPENDS+=	xine-lib>=1rc0anb3:../../graphics/xine-lib

BUILD_DIRS=	${WRKSRC}/src/audio_out

do-install:
	cd ${WRKSRC}/src/audio_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_ao_out_arts.la ${PREFIX}/lib/xine/plugins/1.0.0/

.include "../../audio/arts/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
