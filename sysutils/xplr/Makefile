# $NetBSD: Makefile,v 1.4 2021/04/10 21:18:15 pin Exp $

DISTNAME=	xplr-0.3.13
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sayanarijit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sayanarijit/xplr/
COMMENT=	Hackable, minimal, fast TUI file explorer
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/xplr ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
