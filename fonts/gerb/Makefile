# $NetBSD: Makefile,v 1.7 2023/10/24 22:09:07 wiz Exp $

DISTNAME=	gerb-0.0.1alpha20230427
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=epilys/}
GITHUB_PROJECT=	gerb
GITHUB_TAG=	v0.0.1-alpha+2023-04-27

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/epilys/gerb/
COMMENT=	Graphical font editor in GTK and Rust
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/gerb-${GITHUB_TAG:S/v//:S/+/-/}

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk3}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gerb \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python311/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
