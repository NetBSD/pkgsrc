# $NetBSD: Makefile,v 1.4 2023/11/12 17:01:14 pin Exp $

DISTNAME=	tailspin-2.1.0
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
