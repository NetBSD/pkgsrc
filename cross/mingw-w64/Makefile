# $NetBSD: Makefile,v 1.7 2024/02/10 00:53:34 ryoon Exp $

DISTNAME=		mingw-w64-11.0.1
CATEGORIES=		cross
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://mingw-w64.org/
COMMENT=		Cross toolchains for win32 and win64 cross-development

META_PACKAGE=		yes

DEPENDS+=		mingw-w64-x86_64-gcc-[0-9]*:../../cross/mingw-w64-x86_64-gcc
DEPENDS+=		mingw-w64-x86_64-gcc-winpthreads-[0-9]*:../../cross/mingw-w64-x86_64-gcc-winpthreads
DEPENDS+=		mingw-w64-i686-gcc-[0-9]*:../../cross/mingw-w64-i686-gcc
DEPENDS+=		mingw-w64-i686-gcc-winpthreads-[0-9]*:../../cross/mingw-w64-i686-gcc-winpthreads

.include "../../mk/bsd.pkg.mk"
