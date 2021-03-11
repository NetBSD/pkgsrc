# $NetBSD: Makefile,v 1.5 2021/03/11 15:31:24 fcambus Exp $

DISTNAME=	uthash-2.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=troydhanson/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://troydhanson.github.io/uthash/
COMMENT=	Hash table, implemented in C
LICENSE=	2-clause-bsd

NO_BUILD=		yes
INSTALLATION_DIRS+=	include share/doc/uthash

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/uthash
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
