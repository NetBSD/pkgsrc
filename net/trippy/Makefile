# $NetBSD: Makefile,v 1.3 2022/05/18 12:08:44 pin Exp $

DISTNAME=	trippy-0.4.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fujiapple852/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/fujiapple852/trippy/
COMMENT=	Network diagnostic tool
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/trip \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
