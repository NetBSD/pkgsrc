# $NetBSD: Makefile,v 1.2 2019/04/29 00:18:14 gdt Exp $

DISTNAME=	uthash-2.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=troydhanson/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://troydhanson.github.io/uthash/
COMMENT=	Hash table, implemented in C
LICENSE=	2-clause-bsd

NO_BUILD=		yes
INSTALLATION_DIRS+=	include share/doc/uthash

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/uthash
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
