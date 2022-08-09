# $NetBSD: Makefile,v 1.2 2022/08/09 19:09:30 pin Exp $

DISTNAME=	parallel-disk-usage-0.8.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=KSXGitHub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KSXGitHub/parallel-disk-usage/
COMMENT=	Highly parallelized, blazing fast directory tree analyzer
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pdu \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
