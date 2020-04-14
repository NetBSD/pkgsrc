# $NetBSD: Makefile,v 1.1 2020/04/14 14:07:50 ryoon Exp $

DISTNAME=	snowball-2.0.0
PKGNAME=	libstemmer-2.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=snowballstem/}
GITHUB_PROJECT=	snowball
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://snowballstem.org/
COMMENT=	Snowball compiler and the stemming algorithms
LICENSE=	modified-bsd

USE_TOOLS+=	gmake perl
MAKE_FILE=	GNUmakefile

INSTALLATION_DIRS+=	bin include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/libstemmer.h \
		${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libstemmer.so.0.0.0 \
		${DESTDIR}${PREFIX}/lib
	${LN} -sf libstemmer.so.0.0.0 \
		${DESTDIR}${PREFIX}/lib/libstemmer.so.0
	${LN} -sf libstemmer.so.0.0.0 \
		${DESTDIR}${PREFIX}/lib/libstemmer.so

.include "../../mk/bsd.pkg.mk"
