# $NetBSD: Makefile,v 1.1.1.1 2003/07/26 23:06:11 jmmv Exp $
#

.include "../../devel/SDL/Makefile.common"

PKGNAME=	${DISTNAME:S/SDL/SDL-nas/}
CATEGORIES+=	audio

COMMENT=	SDL plugin to output sound through the Network Audio System

CONFIGURE_ARGS+=	--enable-nas

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILD_DIRS=		${WRKSRC}/src/audio/nas

do-install:
	cd ${WRKSRC}/src/audio/nas && ${SHLIBTOOL} --mode=install \
		${INSTALL} libaudio_nas.la ${PREFIX}/lib

BUILDLINK_DEPENDS.SDL=	SDL>=1.2.5nb6

.include "../../audio/nas/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
