# $NetBSD: Makefile,v 1.2 2008/06/21 20:46:05 bjs Exp $
#

DISTNAME=	qjackctl-0.3.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qjackctl/}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://qjackctl.sourceforge.net/
COMMENT=	JACK Audio Connection Kit Qt4 GUI

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=	xdg-1.4

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.fast.prefs.mk"

CONFIGURE_ARGS+=	--with-qt=${QTDIR:Q}
.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--without-alsa
.endif

.include "../../audio/jack-devel/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
