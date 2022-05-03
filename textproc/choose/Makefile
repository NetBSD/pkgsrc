# $NetBSD: Makefile,v 1.1 2022/05/03 19:17:22 pin Exp $

DISTNAME=	choose-1.3.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=theryangeary/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/theryangeary/choose/
COMMENT=	Human-friendly and fast alternative to cut and (sometimes) awk
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/choose \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
