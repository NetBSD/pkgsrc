# $NetBSD: Makefile,v 1.84 2024/05/29 16:32:23 adam Exp $

DISTNAME=	gobby-0.6.0
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=gobby/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gobby/gobby/wiki
COMMENT=	Multi-Platform Collaborative Editor
LICENSE=	isc

# for m4 fragments for autoconf/automake
TOOL_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4
TOOL_DEPENDS+=	yelp-tools-[0-9]*:../../textproc/yelp-tools

USE_LANGUAGES=		c c++11
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf automake autoreconf
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../editors/libinfinity/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gsasl/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
