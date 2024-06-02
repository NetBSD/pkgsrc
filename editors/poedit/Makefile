# $NetBSD: Makefile,v 1.122 2024/06/02 12:35:38 ryoon Exp $

VERSION=	2.3
DISTNAME=	poedit-${VERSION}
PKGREVISION=	29
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=vslavik/}
GITHUB_RELEASE=	v${VERSION}-oss

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.poedit.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor
LICENSE=	mit

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_LANGUAGES=		c c++
FORCE_CXX_STD=		c++17
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config zip:run
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=		--with-boost=${BUILDLINK_PREFIX.boost-libs}
GNU_CONFIGURE_WX_VERSION=	no

CXXFLAGS+=		-fpermissive
BUILDLINK_TRANSFORM+=	rm:-Wall
BUILDLINK_TRANSFORM+=	rm:-Wextra

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/gtkspell3/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/lucene++/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
