# $NetBSD: Makefile,v 1.11 2004/10/03 00:13:10 tv Exp $
#

.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME:=	${PKGNAME:S/lib/arts/}
PKGREVISION=	1

CATEGORIES=	audio

DEPENDS+=	xine-lib>=1rc3a:../../multimedia/xine-lib

BUILD_DIRS=	${WRKSRC}/src/audio_out

do-install:
	cd ${WRKSRC}/src/audio_out && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
		xineplug_ao_out_arts.la ${PREFIX}/lib/xine/plugins/1.0.0

.include "../../audio/arts/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
