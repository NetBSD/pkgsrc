# $NetBSD: Makefile,v 1.17 2021/05/01 19:09:14 pin Exp $

DISTNAME=	xplr-0.5.12
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=sayanarijit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sayanarijit/xplr/
COMMENT=	Hackable, minimal, fast TUI file explorer
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c
USE_TOOLS+=	bash:run

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/xplr ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
