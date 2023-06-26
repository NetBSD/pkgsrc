# $NetBSD: Makefile,v 1.1 2023/06/26 11:47:35 wiz Exp $

DISTNAME=	diesel-cli-2.1.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=diesel-rs/}
GITHUB_PROJECT=	diesel
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://diesel.rs/
COMMENT=	CLI for the Diesel crate
LICENSE=	apache-2.0 OR mit

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions
INSTALLATION_DIRS+=	share/fish/vendor_completions.d

DIESEL_BINARY=		${WRKSRC}/target/release/diesel

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib

post-build:
	cd ${WRKSRC} && ${DIESEL_BINARY} completions bash > diesel.bash
	cd ${WRKSRC} && ${DIESEL_BINARY} completions zsh > diesel.zsh
	cd ${WRKSRC} && ${DIESEL_BINARY} completions fish > diesel.fish

do-install:
	${INSTALL_PROGRAM} ${DIESEL_BINARY} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/diesel.bash ${DESTDIR}${PREFIX}/share/bash-completion/completions/diesel
	${INSTALL_PROGRAM} ${WRKSRC}/diesel.zsh ${DESTDIR}${PREFIX}/share/zsh/site-functions/_diesel
	${INSTALL_PROGRAM} ${WRKSRC}/diesel.fish ${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/diesel.fish

.include "../../lang/rust/cargo.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
