# $NetBSD: Makefile,v 1.98 2026/10/27 07:59:32 wiz Exp $

DISTNAME=	keepassxc-2.8.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=keepassxreboot/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://keepassxc.org/
COMMENT=	Password generator and manager
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-lgpl-v2 AND gnu-lgpl-v3 AND mit AND cc0-1.0-universal

TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor

SUPERSEDES+=	keepassx-[0-9]*
SUPERSEDES+=	keepassx0-[0-9]*

# botan3
GCC_REQD+=	11

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DKEEPASSXC_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DASCIIDOCTOR_EXE=${PREFIX}/bin/asciidoctor${RUBY_SUFFIX}

.include "options.mk"

.include "../../archivers/minizip/buildlink3.mk"
.include "../../converters/qrencode/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
# does not support editline
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../security/botan3/buildlink3.mk"
.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../security/zxcvbn-c/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
