# $NetBSD: Makefile,v 1.3 2016/06/19 16:23:59 wiz Exp $

DISTNAME=		mingw-3.3.1
PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mingw.sourceforge.net/
COMMENT=		GCC tools for win32 cross-development

META_PACKAGE=		yes

.include "../../cross/mingw-binutils/buildlink3.mk"
.include "../../cross/mingw-gcc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
