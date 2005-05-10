# $NetBSD: Makefile,v 1.12 2005/05/10 00:18:03 reed Exp $
#

.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/esound/}
CATEGORIES=	audio
COMMENT=	The esound audio output plugin for xine-lib

DEPENDS+=	xine-lib>=1rc3a:../../multimedia/xine-lib

BUILD_DIRS=	${WRKSRC}/src/audio_out

do-install:
	cd ${WRKSRC}/src/audio_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_ao_out_esd.la ${PREFIX}/lib/xine/plugins/1.0.1/

.include "../../audio/esound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
