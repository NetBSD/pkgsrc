# $NetBSD: Makefile,v 1.26 2025/06/06 21:20:14 wiz Exp $

DISTNAME=	jj-0.30.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=martinvonz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/martinvonz/jj/
COMMENT=	Git-compatible DVCS that is both simple and powerful
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/jj \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
