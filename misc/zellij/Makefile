# $NetBSD: Makefile,v 1.1 2026/05/20 14:21:02 pin Exp $

DISTNAME=	zellij-0.44.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=zellij-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zellij.dev/
COMMENT=	Terminal workspace with batteries included
LICENSE=	mit

TOOL_DEPENDS+=	go-md2man-[0-9]*:../../textproc/go-md2man

.include "cargo-depends.mk"

RUST_REQ=	1.92.0
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config gmake perl

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/applications

PREPEND_PATH+=	${PREFIX}/gnu/bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

# Use go-md2man to generate manpages and install them
post-install:
	go-md2man < ${WRKSRC}/docs/MANPAGE.md > ${WRKSRC}/docs/zellij.1
	${INSTALL_MAN} ${WRKSRC}/docs/zellij.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/assets/zellij.desktop \
		${DESTDIR}${PREFIX}/share/applications

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
