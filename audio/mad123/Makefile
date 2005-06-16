# $NetBSD: Makefile,v 1.15 2005/06/16 06:57:39 jlam Exp $
#

DISTNAME=	mad123-0.8.5
CATEGORIES=	audio
MASTER_SITES=	http://www.mctavish.co.uk/mad123/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mctavish.co.uk/mad123/
COMMENT=	Command-line MPEG audio player

PKG_OPTIONS_VAR=	PKG_OPTIONS.mad123
PKG_SUPPORTED_OPTIONS=	arts oss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Marts)
MAKE_FLAGS+=	USE_ARTS=yes
.include "../../audio/arts/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Moss)
.  include "../../mk/ossaudio.buildlink3.mk"
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mad123 ${PREFIX}/bin/mad123
	${INSTALL_MAN} ${WRKSRC}/mad123.1 ${PREFIX}/man/man1/

.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
