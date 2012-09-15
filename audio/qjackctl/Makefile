# $NetBSD: Makefile,v 1.19 2012/09/15 10:03:43 obache Exp $
#

DISTNAME=	qjackctl-0.3.3
PKGREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qjackctl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
