# $NetBSD: Makefile,v 1.1 2022/09/27 07:48:43 pin Exp $

DISTNAME=	aschord-0.3.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=yzhong52/}
GITHUB_PROJECT=	ascii_chord
GITHUB_TAG=	b834ed88df17b026d638a7da2ff7810d6e313698

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yzhong52/ascii_chord/
COMMENT=	Print guitar chord with ascii characters given its name
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/aschord \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
