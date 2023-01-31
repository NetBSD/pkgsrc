# $NetBSD: Makefile,v 1.14 2023/01/31 12:33:07 pin Exp $

DISTNAME=	hgrep-0.3.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rhysd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/rhysd/hgrep/
COMMENT=	Grep with human-friendly search output
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		ripgrep syntect-printer

.if ${MACHINE_ARCH} == "powerpc"
# sneak in -latomic in the linker invocation
BUILDLINK_TRANSFORM+=	l:execinfo:execinfo:atomic
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/hgrep \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/atomic64.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
