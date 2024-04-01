# $NetBSD: Makefile,v 1.9 2024/04/01 19:12:44 pin Exp $

DISTNAME=	tailspin-3.0.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=bensadeh/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/bensadeh/tailspin/
COMMENT=	Log file highlighter
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/tspin.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tspin.1

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
