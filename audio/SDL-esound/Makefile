# $NetBSD: Makefile,v 1.1.1.1 2003/07/26 21:43:34 jmmv Exp $
#

.include "../../devel/SDL/Makefile.common"

PKGNAME=	${DISTNAME:S/SDL/SDL-esound/}
CATEGORIES+=	audio gnome

COMMENT=	SDL plugin to output sound through the esound daemon

CONFIGURE_ARGS+=	--enable-esd

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILD_DIRS=		${WRKSRC}/src/audio/esd

do-install:
	cd ${WRKSRC}/src/audio/esd && ${SHLIBTOOL} --mode=install \
		${INSTALL} libaudio_esd.la ${PREFIX}/lib

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
