# $NetBSD: Makefile,v 1.41 2009/04/08 23:11:13 joerg Exp $

META_PACKAGE=		# empty

.include "../../lang/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-${SWIPLVERS}
CATEGORIES=		lang

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler suite

DEPENDS+=		swi-prolog-lite-${SWIPLVERS}{,nb[0-9]*}:../../lang/swi-prolog-lite
DEPENDS+=		swi-prolog-packages-${SWIPLVERS}{,nb[0-9]*}:../../lang/swi-prolog-packages

.include "../../mk/bsd.pkg.mk"
