# $NetBSD: Makefile,v 1.18 2012/09/15 10:05:44 obache Exp $
#

DISTNAME=	tellico-1.3.6
PKGREVISION=	22
CATEGORIES=	misc
MASTER_SITES=	http://www.periapsis.org/tellico/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.periapsis.org/tellico/
COMMENT=	KDE application for organizing your collections

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl:run pkg-config

REPLACE_PERL+=		src/core/tellico-1-3-update.pl
REPLACE_PYTHON+=	src/fetch/scripts/dark_horse_comics.py
REPLACE_PYTHON+=	src/fetch/scripts/fr.allocine.py
REPLACE_PYTHON+=	src/fetch/scripts/ministerio_de_cultura.py
REPLACE_PYTHON+=	src/translators/griffith2tellico.py
REPLACE_RUBY+=		src/fetch/scripts/boardgamegeek.rb

.include "options.mk"

.include "../../audio/taglib/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/exempi/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../misc/kdepim3/buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
