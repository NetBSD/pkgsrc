# $NetBSD: Makefile,v 1.28 2012/02/05 20:39:50 sbd Exp $
#

DISTNAME=	mad123-0.8.5
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://www.mctavish.co.uk/mad123/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mctavish.co.uk/mad123/
COMMENT=	Command-line MPEG audio player

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.mad123
PKG_SUPPORTED_OPTIONS=	arts oss sun
PKG_SUGGESTED_OPTIONS+=	oss
.if ${OPSYS} != "DragonFly" && ${OPSYS} != "Linux"
PKG_SUGGESTED_OPTIONS+=	sun
.endif
.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+= arts
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Marts)
MAKE_FLAGS+=	USE_ARTS=yes
.include "../../audio/arts/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Moss)
MAKE_FLAGS+=	USE_OSS=yes
.  include "../../mk/oss.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msun)
MAKE_FLAGS+=	USE_SUN=yes
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mad123 ${DESTDIR}${PREFIX}/bin/mad123
	${INSTALL_MAN} ${WRKSRC}/mad123.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
