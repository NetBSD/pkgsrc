# $NetBSD: Makefile,v 1.11 2024/08/10 15:36:47 pin Exp $

DISTNAME=	refi-3.2.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=miicat/}
GITLAB_PROJECT=	refi
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/miicat/refi/
COMMENT=	Rename files in numberic order
LICENSE=	gnu-agpl-v3

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/refi-v3.2.1-6aeb18ad8d8d9afbb179003a956c85542981b0d3

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/refi \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
