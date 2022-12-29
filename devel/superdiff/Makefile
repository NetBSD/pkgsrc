# $NetBSD: Makefile,v 1.1 2022/12/29 08:07:22 pin Exp $

DISTNAME=	superdiff-2.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cheukyin699/}
GITHUB_TAG=	24af81652102a178e8c240474d69ce9fb765ab82

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
