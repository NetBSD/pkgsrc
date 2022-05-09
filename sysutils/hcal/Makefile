# $NetBSD: Makefile,v 1.4 2022/05/09 21:50:09 pin Exp $

DISTNAME=	hcal-0.3.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=0xflotus/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/0xflotus/hcal/
COMMENT=	Hexadecimal calendar in terminal for programmers
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/hcal \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
