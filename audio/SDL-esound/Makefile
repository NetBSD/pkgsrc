# $NetBSD: Makefile,v 1.6 2005/01/05 12:58:05 wiz Exp $
#

.include "../../devel/SDL/Makefile.common"

PKGNAME=	${DISTNAME:S/SDL/SDL-esound/}

CATEGORIES+=	audio gnome

COMMENT=	SDL plugin to output sound through the esound daemon

CONFIGURE_ARGS+=	--enable-esd

SHLIBTOOL_OVERRIDE=	libtool

BUILD_DIRS=		${WRKSRC}/src/audio/esd

do-install:
	cd ${WRKSRC}/src/audio/esd && ${SHLIBTOOL} --mode=install \
		${INSTALL_DATA} libaudio_esd.la ${PREFIX}/lib

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
