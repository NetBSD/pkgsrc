# $NetBSD: Makefile,v 1.5 2022/02/21 09:43:40 pin Exp $

DISTNAME=	jless-0.7.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=PaulJuliusMartinez/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PaulJuliusMartinez/jless/
COMMENT=	Command-line pager for JSON data
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

# jless command conflicts with misc/ja-less
# Rename it at install time

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/jless \
		${DESTDIR}${PREFIX}/bin/j_less

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
