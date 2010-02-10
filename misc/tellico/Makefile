# $NetBSD: Makefile,v 1.18 2010/02/10 19:17:42 joerg Exp $
#

DISTNAME=	tellico-1.3.6
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://www.periapsis.org/tellico/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.periapsis.org/tellico/
COMMENT=	KDE application for organizing your collections

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl:build pkg-config

.include "options.mk"

.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/exempi/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../misc/kdepim3/buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
