# $NetBSD: Makefile,v 1.39 2014/10/07 16:47:27 adam Exp $
#

DISTNAME=	ibus-chewing-1.4.10.1-Source
PKGNAME=	${DISTNAME:S/-Source//}
PKGREVISION=	1
CATEGORIES=	inputmethod chinese
MASTER_SITES=	https://github.com/definite/ibus-chewing/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Chewing engine for IBus input platform
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		gob2-[0-9]*:../../devel/gob2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config
TOOLS_NOOP+=		msgmerge xgettext

GCONF_SCHEMAS=	ibus-chewing.schemas
CMAKE_ARGS+=	-DLIBEXEC_DIR=${PREFIX}/libexec
CMAKE_ARGS+=	-DGCONF_SCHEMAS_INSTALLED_DIR:PATH=${GCONF_SCHEMAS_DIR}

BUILD_TARGET=	all translations

.include "../../devel/GConf/schemas.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
