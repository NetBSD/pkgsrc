# $NetBSD: Makefile,v 1.1.1.1 2004/01/22 16:07:23 jmmv Exp $
#

.include "../../graphics/xine-lib/Makefile.common"

PKGNAME:=	${PKGNAME:S/lib/esound/}
CATEGORIES=	audio

DEPENDS+=	xine-lib>=1rc0anb3:../../graphics/xine-lib

BUILD_DIRS=	${WRKSRC}/src/audio_out

do-install:
	cd ${WRKSRC}/src/audio_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_ao_out_esd.la ${PREFIX}/lib/xine/plugins/1.0.0/

.include "../../audio/esound/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
