# $NetBSD: Makefile,v 1.1 2023/11/03 08:17:12 pin Exp $

DISTNAME=	tailspin-1.6.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=bensadeh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bensadeh/tailspin/
COMMENT=	Log file highlighter
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# The binary needs to be renamed to avoid potential conflicts.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/spin \
		${DESTDIR}${PREFIX}/bin/tspin
	${INSTALL_MAN} ${WRKSRC}/man/spin.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tspin.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
