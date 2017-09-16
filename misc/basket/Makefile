# $NetBSD: Makefile,v 1.40 2017/09/16 08:32:38 wiz Exp $

DISTNAME=		basket-1.0.2
PKGREVISION=		35
CATEGORIES=		misc
#MASTER_SITES=		http://basket.kde.org/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://basket-notepads.github.io/
COMMENT=		Feature-rich note-taking KDE application

USE_TOOLS+=		gmake msgfmt pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
SET_LIBDIR=		yes

BUILDLINK_DEPMETHOD.qt3-tools=	full

.include "../../security/gpgme/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../misc/kdepim3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
