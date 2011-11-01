# $NetBSD: Makefile,v 1.14 2011/11/01 06:02:03 sbd Exp $

DISTNAME=		basket-1.0.2
PKGREVISION=		12
CATEGORIES=		misc
MASTER_SITES=		http://basket.kde.org/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://basket.kde.org/
COMMENT=		Feature-rich note-taking KDE application

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake msgfmt pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../security/gpgme/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../misc/kdepim3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
