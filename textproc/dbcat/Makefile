# $NetBSD: Makefile,v 1.1 2022/02/09 17:07:06 pin Exp $

DISTNAME=	dbcat-0.1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=NishantJoshi00/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/NishantJoshi00/dbcat/
COMMENT=	Equivalent of cat(1) for viewing sqlite database
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/dbcat ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
