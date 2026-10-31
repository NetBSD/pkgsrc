# $NetBSD: Makefile,v 1.9 2026/10/31 12:20:17 js Exp $

DISTNAME=		mingw-w64-14.0.0
CATEGORIES=		cross
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://mingw-w64.org/
COMMENT=		Cross toolchains for win32 and win64 cross-development

META_PACKAGE=		yes

DEPENDS+=		mingw-w64-x86_64-gcc-ucrt-[0-9]*:../../cross/mingw-w64-x86_64-gcc
DEPENDS+=		mingw-w64-x86_64-gcc-msvcrt-[0-9]*:../../cross/mingw-w64-x86_64-gcc-msvcrt
DEPENDS+=		mingw-w64-x86_64-gcc-winpthreads-ucrt-[0-9]*:../../cross/mingw-w64-x86_64-gcc-winpthreads
DEPENDS+=		mingw-w64-i686-gcc-ucrt-[0-9]*:../../cross/mingw-w64-i686-gcc
DEPENDS+=		mingw-w64-i686-gcc-msvcrt-[0-9]*:../../cross/mingw-w64-i686-gcc-msvcrt
DEPENDS+=		mingw-w64-i686-gcc-winpthreads-ucrt-[0-9]*:../../cross/mingw-w64-i686-gcc-winpthreads

.include "../../mk/bsd.pkg.mk"
