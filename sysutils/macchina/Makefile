# $NetBSD: Makefile,v 1.7 2021/03/11 21:31:42 pin Exp $

DISTNAME=	macchina-0.5.7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=grtcdr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/grtcdr/macchina/
COMMENT=	Basic system information fetcher
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/macchina ${DESTDIR}${PREFIX}/bin

DEPENDS+=	ripgrep-[0-9]*:../../textproc/ripgrep
DEPENDS+=	wmctrl-[0-9]*:../../wm/wmctrl

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
