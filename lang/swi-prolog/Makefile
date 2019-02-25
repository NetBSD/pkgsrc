# $NetBSD: Makefile,v 1.42 2019/02/25 15:20:44 leot Exp $

META_PACKAGE=		yes

.include "../../lang/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-${SWIPLVERS}
CATEGORIES=		lang

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler suite

DEPENDS+=		swi-prolog-lite-${SWIPLVERS}{,nb[0-9]*}:../../lang/swi-prolog-lite
DEPENDS+=		swi-prolog-packages-${SWIPLVERS}{,nb[0-9]*}:../../lang/swi-prolog-packages

.include "../../mk/bsd.pkg.mk"
