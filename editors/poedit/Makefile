# $NetBSD: Makefile,v 1.92 2020/03/08 16:49:23 wiz Exp $

VERSION=	2.3
DISTNAME=	poedit-${VERSION}
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=vslavik/}
GITHUB_RELEASE=	v${VERSION}-oss

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.poedit.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor
LICENSE=	mit

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config zip:run
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}

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
