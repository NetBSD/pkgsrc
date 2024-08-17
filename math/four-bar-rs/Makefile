# $NetBSD: Makefile,v 1.15 2024/08/17 22:07:06 wiz Exp $

DISTNAME=	four-bar-rs-7.0.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=KmolYuan/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/KmolYuan/four-bar-rs/
COMMENT=	Simulator and synthesizing tool for four-bar linkage mechanism
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk3}/lib

# build.rs tries to run git to get the hash, but the distfile doesn't have
# a repository included, so this will fail
SUBST_CLASSES+=		git
SUBST_SED.git+=		-e 's,env!("GIT_HASH"),"unknown",'
SUBST_FILES.git+=	four-bar-ui/src/app.rs
SUBST_MESSAGE.git=	Fixing build problem.
SUBST_STAGE.git=	post-extract

pre-build:
	${RM} -f ${WRKSRC}/four-bar-ui/build.rs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/four-bar \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
