# $NetBSD: Makefile,v 1.57 2019/11/02 21:09:16 rillig Exp $
#

DISTNAME=	qjackctl-0.4.2
PKGREVISION=	21
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qjackctl/}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qjackctl.sourceforge.net/
COMMENT=	JACK Audio Connection Kit Qt GUI
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--without-alsa
.endif

CONFIGURE_ARGS+=	--with-qt5=${QTDIR}

.include "../../audio/jack/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.  include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
