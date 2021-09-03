# $NetBSD: Makefile,v 1.5 2021/09/03 01:53:52 bacon Exp $

DISTNAME=	biolibc-0.2.0.1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	f6de6e02d75bc6298c0885e45176b3b9c7f84c29

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
