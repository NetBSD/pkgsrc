# $NetBSD: Makefile,v 1.39 2006/08/30 00:00:30 markd Exp $

.include "../../lang/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-${SWIPLVERS}
CATEGORIES=		lang

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler suite

DEPENDS+=		swi-prolog-lite-${SWIPLVERS}{,nb[0-9]*}:../../lang/swi-prolog-lite
DEPENDS+=		swi-prolog-packages-${SWIPLVERS}{,nb[0-9]*}:../../lang/swi-prolog-packages

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_MTREE=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
