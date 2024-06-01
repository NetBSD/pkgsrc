# $NetBSD: Makefile,v 1.72 2024/06/01 14:02:48 bsiegert Exp $

DISTNAME=	coyim-0.4.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=coyim/}
PKGREVISION=	11
CATEGORIES=	chat
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://coy.im/
COMMENT=	Safe and secure by default chat client
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config gmake

# for patching
EXTRACT_ONLY=	${DEFAULT_DISTFILES} github.com_awnumar_memcall_@v_v0.1.2.zip

GO_DIST_BASE=		${PKGNAME_NOREV}
GO_SRCPATH=		github.com/coyim/coyim
GO_BUILD_PATTERN=	${GO_SRCPATH}

MAKE_ENV+=	CGO_LDFLAGS_ALLOW=".*"
MAKE_ENV+=	CGO_CFLAGS_ALLOW=".*"
MAKE_ENV+=	CGO_CXXFLAGS_ALLOW=".*"
MAKE_ENV+=	CGO_CPPFLAGS_ALLOW=".*"

COYIM_ICON=		coyim.png
COYIM_ICON_SRC=		${WRKSRC}/build/osx/mac-bundle/coyim.iconset/icon_32x32@2x.png

INSTALLATION_DIRS+=	share/applications share/pixmaps

CHECK_PORTABILITY_SKIP+=	build/osx/mac-bundle/coyim-launcher.sh

CHECK_RELRO_SKIP=	bin/coyim

post-extract:
	${CP} ${FILESDIR}/go.* ${WRKSRC}
	${RM} -rf ${WRKSRC}/vendor

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/coyim ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${COYIM_ICON_SRC} ${DESTDIR}${PREFIX}/share/pixmaps/${COYIM_ICON}

.include "go-modules.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.include "../../x11/gtk-mac-integration/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
