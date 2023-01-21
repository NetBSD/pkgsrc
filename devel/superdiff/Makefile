# $NetBSD: Makefile,v 1.3 2023/01/21 11:41:07 pin Exp $

DISTNAME=	superdiff-2.1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cheukyin699/}
GITHUB_TAG=	113612d4ee4bed8f7f24ab01ea5e0b529016c32a

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
