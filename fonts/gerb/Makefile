# $NetBSD: Makefile,v 1.10 2023/11/14 14:01:50 wiz Exp $

DISTNAME=	gerb-0.0.1alpha20230427
PKGREVISION=	5
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
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python311/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
