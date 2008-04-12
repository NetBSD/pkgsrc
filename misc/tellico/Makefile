# $NetBSD: Makefile,v 1.1.1.1 2008/04/12 10:59:26 wiz Exp $
#

DISTNAME=	tellico-1.3.1
CATEGORIES=	misc
MASTER_SITES=	http://www.periapsis.org/tellico/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.periapsis.org/tellico/
COMMENT=	KDE application for organizing your collections

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_DIRS+=		kde3-1.0
USE_TOOLS+=		gmake pkg-config

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
