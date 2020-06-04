# $NetBSD: Makefile,v 1.8 2020/06/04 16:46:35 micha Exp $

DISTNAME=	utf8proc-2.5.0
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=JuliaLang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://julialang.org/utf8proc/
COMMENT=	C library for processing Unicode data
LICENSE=	mit

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes

INSTALLATION_DIRS=	include lib lib/pkgconfig

# Use ABI version from CMakeLists.txt to stay compatible with cmake builds
MAJOR=	2
MINOR=	3
PATCH=	2

do-configure:
	cd ${WRKSRC} && ${SED}						\
		-e 's#PREFIX#${PREFIX}#'				\
		-e 's#LIBDIR#lib#'					\
		-e 's#INCLUDEDIR#include#'				\
		-e 's#VERSION#${MAJOR}.${MINOR}.${PATCH}#'		\
		-e 's#Description:.*$$#Description: ${COMMENT}#'	\
		libutf8proc.pc.in >libutf8proc.pc

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --tag=CC --mode=compile		\
		${CC} ${CPPFLAGS} ${CFLAGS} -c -o utf8proc.lo utf8proc.c
	cd ${WRKSRC} && ${LIBTOOL} --tag=CC --mode=link			\
		${CC} ${LDFLAGS} -o libutf8proc.la utf8proc.lo		\
			-rpath ${PREFIX}/lib				\
			-version-number ${MAJOR}:${MINOR}:${PATCH}

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install			\
		${INSTALL_LIB} libutf8proc.la ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC} &&							\
		${INSTALL_DATA} utf8proc.h ${DESTDIR}${PREFIX}/include
	cd ${WRKSRC} &&							\
		${INSTALL_DATA} libutf8proc.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
