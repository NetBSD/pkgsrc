# $NetBSD: Makefile,v 1.1 2021/11/14 17:16:53 pin Exp $

DISTNAME=	felix-0.2.8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=kyoheiu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/kyoheiu/felix/
COMMENT=	TUI file manager with vim-like key mapping
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "cargo-depends.mk"

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

INSTALLATION_DIRS=	bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libxcb}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/fx ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
