# $NetBSD: Makefile,v 1.26 2022/07/02 16:53:09 ryoon Exp $

DISTNAME=	quassel-0.14.0
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	https://quassel-irc.org/pub/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://quassel-irc.org/
COMMENT=	Modern, cross-platform, distributed IRC client
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_TOOLS+=	bash perl
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

GCC_REQD+=	5 # C++14

REPLACE_BASH+=	po/update.sh
REPLACE_BASH+=	scripts/tx-sync.sh

REPLACE_PERL+=	data/scripts/inxi
REPLACE_PERL+=	data/scripts/mpris

.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libdbusmenu-qt5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
