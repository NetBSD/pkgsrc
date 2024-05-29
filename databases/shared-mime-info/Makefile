# $NetBSD: Makefile,v 1.83 2024/05/29 16:31:54 adam Exp $

DISTNAME=	shared-mime-info-2.4
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://gitlab.freedesktop.org/xdg/shared-mime-info/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/shared-mime-info
COMMENT=	Core database of common types
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=		gettext-tools>=0.19.8:../../devel/gettext-tools
TOOL_DEPENDS+=		xmlto>=0:../../textproc/xmlto

USE_LANGUAGES+=		c99 c++
USE_TOOLS+=		bash:test msgfmt pkg-config xgettext
USE_CXX_FEATURES=	filesystem

.include "../../mk/bsd.prefs.mk"

# msgfmt: unknown option --xml
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""

FILES_SUBST+=		MIMEDB_PATH="${PREFIX}/share/mime"
FILES_SUBST+=		UPDATE_MIMEDB="${PREFIX}/bin/update-mime-database"

PRINT_PLIST_AWK+=	/^share\/mime\/packages/ { print; next; }
PRINT_PLIST_AWK+=	/^share\/mime/ { next; }

# for tests
.include "../../lang/python/tool.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
