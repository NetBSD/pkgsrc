# $NetBSD: Makefile,v 1.20 2006/01/24 07:31:56 wiz Exp $
#

.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/arts/}
PKGREVISION=	2
CATEGORIES=	audio
COMMENT=	The aRts audio output plugin for xine-lib

DEPENDS+=	xine-lib>=1rc3a:../../multimedia/xine-lib

BUILD_DIRS=	${WRKSRC}/src/audio_out

INSTALLATION_DIRS=	lib/xine/plugins/1.0.3

do-install:
	cd ${WRKSRC}/src/audio_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_ao_out_arts.la ${PREFIX}/lib/xine/plugins/1.0.3

.include "../../audio/arts/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
