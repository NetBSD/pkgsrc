# $NetBSD: Makefile,v 1.32 2004/10/07 12:16:51 markd Exp $

.include "../swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-${SWIPLVERS}
PKGREVISION=		1
CATEGORIES=		lang

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler suite

DEPENDS+=		swi-prolog-lite-${SWIPLVERS}nb1:../swi-prolog-lite
DEPENDS+=		swi-prolog-packages-${SWIPLVERS}nb1:../swi-prolog-packages

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_MTREE=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
