# $NetBSD: Makefile,v 1.1 2021/05/31 07:52:43 pin Exp $

DISTNAME=	gpg-tui-0.1.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=orhun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/orhun/gpg-tui/
COMMENT=	Manage your GnuPG keys with ease
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=			c
USE_TOOLS+=			pkg-config
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgpg-error}/lib
MAKE_ENV+=	RUSTFLAGS=${RUSTFLAGS:Q}


INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gpg-tui ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/gpg-tui.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
