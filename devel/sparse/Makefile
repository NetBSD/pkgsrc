# $NetBSD: Makefile,v 1.18 2025/01/31 10:18:22 wiz Exp $

DISTNAME=	sparse-0.6.4
CATEGORIES=	devel lang
MASTER_SITES=	https://kernel.org/pub/software/devel/sparse/dist/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://kernel.org/pub/software/devel/sparse/
COMMENT=	Semantic parser for C
LICENSE=	mit

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99

TOOLS_CREATE+=			llvm-config
TOOLS_SCRIPT.llvm-config=	exit 1

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/sparse
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
REPLACE_PERL=		cgcc
USE_TOOLS+=		gmake perl:run

CPPFLAGS+=	-D_POSIX_C_SOURCE=200809L
CFLAGS+=	-std=gnu99

MAKE_ENV+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_ENV+=	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
MAKE_ENV+=	INSTALL_MAN=${INSTALL_MAN:Q}

TEST_TARGET=	check

post-install:
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/sparse/

.include "../../mk/bsd.pkg.mk"
