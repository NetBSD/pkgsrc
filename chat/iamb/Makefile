# $NetBSD: Makefile,v 1.1 2023/03/09 10:21:32 pin Exp $

DISTNAME=	iamb-0.0.6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=ulyssa/}
GITHUB_TAG=	10b142c071dbc1b28aa65b51197ed29efdf1e61f

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://iamb.chat/
COMMENT=	Matrix client for Vim addicts
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/iamb \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
