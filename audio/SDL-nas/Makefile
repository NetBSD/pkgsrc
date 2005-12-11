# $NetBSD: Makefile,v 1.11 2005/12/11 09:40:37 wiz Exp $

.include "../../devel/SDL/Makefile.common"

PKGNAME=	${DISTNAME:S/SDL/SDL-nas/}
PKGREVISION=	1

CATEGORIES+=	audio

COMMENT=	SDL plugin to output sound through the Network Audio System

CONFIGURE_ARGS+=	--enable-nas

SHLIBTOOL_OVERRIDE=	libtool

BUILD_DIRS=		${WRKSRC}/src/audio/nas
INSTALLATION_DIRS=	lib

do-install:
	cd ${WRKSRC}/src/audio/nas && ${SHLIBTOOL} --mode=install \
		${INSTALL_DATA} libaudio_nas.la ${PREFIX}/lib

BUILDLINK_DEPENDS.SDL+=	SDL>=1.2.5nb6

.include "../../audio/nas/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
