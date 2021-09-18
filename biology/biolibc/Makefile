# $NetBSD: Makefile,v 1.6 2021/09/18 00:42:39 bacon Exp $

DISTNAME=	biolibc-0.2.0.11
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	65b3b132c813bb04b3a9886d08f51af8137a60e6

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/biolibc
COMMENT=	Low-level high-performance bioinformatics library
LICENSE=	2-clause-bsd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
BUILD_TARGET=	apple
INSTALL_TARGET=	apple-install
.else
INSTALL_TARGET=	install-strip
PLIST.cs=	yes
.endif

MAKE_ENV+=	DYLIB_PATH=${PREFIX}/lib MANDIR=${PREFIX}/${PKGMANDIR}
PLIST_VARS=	cs

pre-build:
	cd ${WRKSRC} && ${MAKE} PREFIX=${PREFIX} depend

.include "../../devel/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
