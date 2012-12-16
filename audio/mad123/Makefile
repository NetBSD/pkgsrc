# $NetBSD: Makefile,v 1.35 2012/12/16 01:51:59 obache Exp $
#

DISTNAME=	mad123-0.8.5
PKGREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	http://www.mctavish.co.uk/mad123/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mctavish.co.uk/mad123/
COMMENT=	Command-line MPEG audio player

USE_TOOLS+=	nroff

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.mad123
PKG_SUPPORTED_OPTIONS=	arts oss sun
PKG_SUGGESTED_OPTIONS+=	oss
.if ${OPSYS} != "DragonFly" && ${OPSYS} != "Linux" && ${OPSYS} != "SunOS"
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

CPPFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mad123 ${DESTDIR}${PREFIX}/bin/mad123
	${INSTALL_MAN} ${WRKSRC}/mad123.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
