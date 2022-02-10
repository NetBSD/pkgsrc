# $NetBSD: Makefile,v 1.2 2022/02/10 07:45:23 wiz Exp $

DISTNAME=	jless-0.7.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=PaulJuliusMartinez/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/PaulJuliusMartinez/jless/
COMMENT=	Command-line pager for JSON data
LICENSE=	mit

CONFLICTS+=	ja-less-[0-9]*

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/jless ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
