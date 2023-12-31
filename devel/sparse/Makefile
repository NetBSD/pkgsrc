# $NetBSD: Makefile,v 1.17 2023/12/31 17:59:47 riastradh Exp $

DISTNAME=	sparse-0.6.4
CATEGORIES=	devel lang
MASTER_SITES=	https://kernel.org/pub/software/devel/sparse/dist/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://kernel.org/pub/software/devel/sparse/
COMMENT=	Semantic parser for C
LICENSE=	mit

TOOLS_CREATE+=			llvm-config
TOOLS_SCRIPT.llvm-config=	exit 1

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/sparse
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
PKGCONFIG_OVERRIDE+=	sparse.pc.in
REPLACE_PERL=		cgcc
USE_TOOLS+=		gmake perl:run

CPPFLAGS+=	-D_POSIX_C_SOURCE=200809L
CFLAGS+=	-std=gnu99

MAKE_ENV+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_ENV+=	INSTALL_MAN=${INSTALL_MAN:Q}

post-install:
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DESTDIR}${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/sparse/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/sparse/

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
