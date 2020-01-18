# $NetBSD: Makefile,v 1.4 2020/01/18 23:30:16 rillig Exp $

DISTNAME=		mingw-3.3.1
PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://mingw.sourceforge.net/
COMMENT=		GCC tools for win32 cross-development

META_PACKAGE=		yes

.include "../../cross/mingw-binutils/buildlink3.mk"
.include "../../cross/mingw-gcc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
