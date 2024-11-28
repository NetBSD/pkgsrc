# $NetBSD: Makefile,v 1.8 2024/11/28 20:36:41 ryoon Exp $

DISTNAME=		mingw-w64-12.0.0
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
