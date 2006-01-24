# $NetBSD: Makefile,v 1.12 2006/01/24 07:31:53 wiz Exp $

.include "../../devel/SDL/Makefile.common"

PKGNAME=	${DISTNAME:S/SDL/SDL-arts/}
PKGREVISION=	2

CATEGORIES+=	audio kde

COMMENT=	SDL plugin to output sound through the aRts sound daemon

CONFIGURE_ARGS+=	--enable-arts

SHLIBTOOL_OVERRIDE=	libtool

BUILD_DIRS=		${WRKSRC}/src/audio/arts
INSTALLATION_DIRS=	lib

do-install:
	cd ${WRKSRC}/src/audio/arts && ${SHLIBTOOL} --mode=install \
		${INSTALL_DATA} libaudio_arts.la ${PREFIX}/lib

.include "../../audio/arts/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
