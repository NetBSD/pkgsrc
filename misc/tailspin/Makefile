# $NetBSD: Makefile,v 1.19 2025/11/07 09:56:18 pin Exp $

DISTNAME=	tailspin-5.5.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=bensadeh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bensadeh/tailspin/
COMMENT=	Log file highlighter
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.85.0

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/tspin.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tspin.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
