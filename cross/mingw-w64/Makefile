# $NetBSD: Makefile,v 1.1 2018/06/07 19:09:24 ryoon Exp $

DISTNAME=		mingw-w64-5.0.4
CATEGORIES=		cross
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://mingw-w64.org/
COMMENT=		Cross toolchains for win32 and win64 cross-development

META_PACKAGE=		yes

DEPENDS+=		mingw-w64-x86_64-gcc-[0-9]*:../../cross/mingw-w64-x86_64-gcc
DEPENDS+=		mingw-w64-i686-gcc-[0-9]*:../../cross/mingw-w64-i686-gcc

.include "../../mk/bsd.pkg.mk"
