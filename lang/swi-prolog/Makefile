# $NetBSD: Makefile,v 1.33 2005/02/21 20:26:12 hubertf Exp $

.include "../swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-${SWIPLVERS}
PKGREVISION=		1
CATEGORIES=		lang

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler suite

DEPENDS+=		swi-prolog-lite-${SWIPLVERS}nb1:../swi-prolog-lite
DEPENDS+=		swi-prolog-packages-${SWIPLVERS}nb1:../swi-prolog-packages

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_MTREE=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
