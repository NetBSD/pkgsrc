# $NetBSD: Makefile,v 1.7 2024/05/29 16:35:19 adam Exp $

DISTNAME=	irdest-ratman-0.3.1
PKGNAME=	${DISTNAME:S/^irdest-//g}
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	https://git.irde.st/we/irdest/-/archive/ratman-${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://irde.st/
COMMENT=	Decentralised peer-to-peer routing daemon
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	pkg-config

CARGO_FEATURES=	daemon util

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ratcat \
	    ${DESTDIR}${PREFIX}/bin/ratcat
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ratctl \
	    ${DESTDIR}${PREFIX}/bin/ratctl
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ratmand \
	    ${DESTDIR}${PREFIX}/bin/ratmand
	${INSTALL_MAN} ${WRKSRC}/docs/man/ratmand.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ratmand.1

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../devel/protobuf/buildlink3.mk"
BUILDLINK_DEPMETHOD.protobuf?=	build
.include "../../security/libsodium/buildlink3.mk"
BUILDLINK_DEPMETHOD.libsodium?=	build
.include "../../mk/bsd.pkg.mk"
