# $NetBSD: Makefile,v 1.2 2003/09/03 19:24:43 drochner Exp $
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
		${INSTALL_DATA} libaudio_esd.la ${PREFIX}/lib

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
