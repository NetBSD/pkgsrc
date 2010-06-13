# $NetBSD: Makefile,v 1.7 2010/06/13 22:43:52 wiz Exp $
#

DISTNAME=	qjackctl-0.3.3
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qjackctl/}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://qjackctl.sourceforge.net/
COMMENT=	JACK Audio Connection Kit Qt4 GUI

PKG_DESTDIR_SUPPORT=	user-destdir


GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.fast.prefs.mk"

CONFIGURE_ARGS+=	--with-qt=${QTDIR:Q}
.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--without-alsa
.endif

.include "../../audio/jack/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
