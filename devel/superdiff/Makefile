# $NetBSD: Makefile,v 1.2 2023/01/02 13:43:29 pin Exp $

DISTNAME=	superdiff-2.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cheukyin699/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cheukyin699/superdiff/
COMMENT=	Find duplicate code blocks in a file
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/superdiff \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
