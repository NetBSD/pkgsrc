# $NetBSD: Makefile,v 1.29 2011/01/13 13:37:13 wiz Exp $
#

DISTNAME=	konversation-1.3.1
PKGREVISION=	2
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_KDE:=konversation/1.3.1/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://konversation.kde.org/
COMMENT=	KDE IRC Client
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+= automoc4>=0.9.87:../../devel/automoc4

USE_CMAKE=	yes
USE_TOOLS+=	perl msgfmt
USE_LANGUAGES=	c c++

REPLACE_PERL+=		data/updaters/konversation-0.19-appearance.pl \
			data/updaters/konversation-0.19-colorcodes.pl \
			data/updaters/konversation-0.19-colors.pl \
			data/updaters/konversation-0.19-custombrowser.pl \
			data/updaters/konversation-0.19-notifylists.pl \
			data/updaters/konversation-0.19-sortorder.pl \
			data/updaters/konversation-0.19-tabplacement.pl \
			data/updaters/konversation-0.20-customfonts.pl \
			data/updaters/konversation-0.20-quickbuttons.pl
REPLACE_BASH+=		data/scripts/mail
USE_TOOLS+=		bash:run

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=		psmisc>=20.1:../../sysutils/psmisc
.endif

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
