# $NetBSD: Makefile,v 1.1 2023/03/29 19:30:20 pin Exp $

DISTNAME=	v0.0.1-alpha+2023-03-28
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=epilys/}
GITHUB_PROJECT=	gerb
GITHUB_TAG=	v0.0.1-alpha+2023-03-28

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/epilys/gerb/
COMMENT=	Graphical font editor in GTK and Rust
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/gerb-0.0.1-alpha-2023-03-28

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk3}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gerb \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python310/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
