# $NetBSD: Makefile,v 1.16 2005/11/11 18:58:18 joerg Exp $
#

DISTNAME=	mad123-0.8.5
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mctavish.co.uk/mad123/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mctavish.co.uk/mad123/
COMMENT=	Command-line MPEG audio player

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.mad123
PKG_SUPPORTED_OPTIONS=	arts oss sun
PKG_DEFAULT_OPTIONS+=	oss
.if ${OPSYS} != "DragonFly"
PKG_DEFAULT_OPTIONS+=	sun
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Marts)
MAKE_FLAGS+=	USE_ARTS=yes
.include "../../audio/arts/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Moss)
MAKE_FLAGS+=	USE_OSS=yes
.  include "../../mk/ossaudio.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msun)
MAKE_FLAGS+=	USE_SUN=yes
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mad123 ${PREFIX}/bin/mad123
	${INSTALL_MAN} ${WRKSRC}/mad123.1 ${PREFIX}/man/man1/

.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
