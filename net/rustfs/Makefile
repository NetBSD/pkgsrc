# $NetBSD: Makefile,v 1.1 2026/11/23 10:32:46 adam Exp $

DISTNAME=	rustfs-1.0.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=rustfs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rustfs/rustfs
COMMENT=	High-performance, distributed object storage system
LICENSE=	apache-2.0

TOOL_DEPENDS+=	protobuf>=0:../../devel/protobuf

CARGO_GITHUB_CRATES+=	rustfs uring eb8fc160e71d804427de1e905f5c226d580f71bf#eb8fc160
CARGO_GITHUB_CRATES+=	s3s-project s3s 5761ddfe4c509fcac87e3b99fd5bd9e176b442c0
SUBST_NOOP_OK.gitcrate=	yes

CARGO_ARGS=	build --release --package rustfs --bin rustfs ${DEFAULT_CARGO_ARGS}
RUST_REQ=	1.99

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rustfs \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
