# $NetBSD: Makefile,v 1.1.1.1 2003/07/26 21:42:50 jmmv Exp $
#

.include "../../devel/SDL/Makefile.common"

PKGNAME=	${DISTNAME:S/SDL/SDL-arts/}
CATEGORIES+=	audio kde

COMMENT=	SDL plugin to output sound through the aRts sound daemon

CONFIGURE_ARGS+=	--enable-arts

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILD_DIRS=		${WRKSRC}/src/audio/arts

do-install:
	cd ${WRKSRC}/src/audio/arts && ${SHLIBTOOL} --mode=install \
		${INSTALL} libaudio_arts.la ${PREFIX}/lib

.include "../../audio/arts/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
