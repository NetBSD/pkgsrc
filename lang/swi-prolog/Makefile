# $NetBSD: Makefile,v 1.31 2004/06/18 22:35:24 markd Exp $

.include "../swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-${SWIPLVERS}
CATEGORIES=		lang

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler suite

DEPENDS+=		swi-prolog-lite-${SWIPLVERS}:../swi-prolog-lite
DEPENDS+=		swi-prolog-packages-${SWIPLVERS}:../swi-prolog-packages

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_MTREE=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
