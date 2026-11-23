# $NetBSD: Makefile,v 1.21 2026/11/23 12:40:22 pin Exp $

DISTNAME=	parallel-disk-usage-0.24.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=KSXGitHub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KSXGitHub/parallel-disk-usage/
COMMENT=	Highly parallelized, blazing fast directory tree analyzer
LICENSE=	apache-2.0

.include "cargo-depends.mk"

#RUST_REQ=		1.101.0-beta.3
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.101.0-beta.3 on amd64
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pdu \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/exports/pdu.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pdu.1


.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
