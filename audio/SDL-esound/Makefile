# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:38 jlam Exp $
#

.include "../../devel/SDL/Makefile.common"

PKGNAME=	${DISTNAME:S/SDL/SDL-esound/}
PKGREVISION=	1

CATEGORIES+=	audio gnome

COMMENT=	SDL plugin to output sound through the esound daemon

CONFIGURE_ARGS+=	--enable-esd

SHLIBTOOL_OVERRIDE=	libtool

BUILD_DIRS=		${WRKSRC}/src/audio/esd
INSTALLATION_DIRS=	lib

do-install:
	cd ${WRKSRC}/src/audio/esd && ${SHLIBTOOL} --mode=install \
		${INSTALL_DATA} libaudio_esd.la ${PREFIX}/lib

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
