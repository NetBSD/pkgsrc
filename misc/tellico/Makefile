# $NetBSD: Makefile,v 1.65 2013/03/31 08:13:30 obache Exp $
#

DISTNAME=	tellico-2.3.5
PKGREVISION=	16
CATEGORIES=	misc
MASTER_SITES=	http://tellico-project.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tellico-project.org/
COMMENT=	Collection manager for KDE
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4-[0-9]*:../../devel/automoc4

REPLACE_PERL+=		src/core/tellico-1-3-update.pl
REPLACE_PYTHON+=	src/fetch/scripts/*.py
REPLACE_PYTHON+=	src/translators/griffith2tellico.py
REPLACE_RUBY+=		src/fetch/scripts/boardgamegeek.rb

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/exempi/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../graphics/libksane/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../multimedia/kdemultimedia4/buildlink3.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
