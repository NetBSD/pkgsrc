# $NetBSD: Makefile,v 1.5 2004/02/25 18:02:08 jmmv Exp $
#

.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME:=	${PKGNAME:S/lib/arts/}
CATEGORIES=	audio

DEPENDS+=	xine-lib>=1rc0anb3:../../multimedia/xine-lib

BUILD_DIRS=	${WRKSRC}/src/audio_out

do-install:
	cd ${WRKSRC}/src/audio_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_ao_out_arts.la ${PREFIX}/lib/xine/plugins/1.0.0

.include "../../audio/arts/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
