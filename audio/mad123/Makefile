# $NetBSD: Makefile,v 1.11 2005/01/29 12:22:27 scw Exp $
#

DISTNAME=	mad123-0.8.5
CATEGORIES=	audio
MASTER_SITES=	http://www.mctavish.co.uk/mad123/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mctavish.co.uk/mad123/
COMMENT=	Command-line MPEG audio player

USE_BUILDLINK3=		yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.mad123
PKG_SUPPORTED_OPTIONS=	arts
.include "../../mk/bsd.options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mad123 ${PREFIX}/bin/mad123
	${INSTALL_MAN} ${WRKSRC}/mad123.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS:Marts)
MAKE_FLAGS+=	USE_ARTS=yes
.include "../../audio/arts/buildlink3.mk"
.endif

.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.if defined(USE_OSS)
.  include "../../mk/ossaudio.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
