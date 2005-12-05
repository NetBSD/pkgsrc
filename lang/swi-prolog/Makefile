# $NetBSD: Makefile,v 1.35 2005/12/05 20:50:28 rillig Exp $

.include "../../lang/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-${SWIPLVERS}
PKGREVISION=		1
CATEGORIES=		lang

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler suite

DEPENDS+=		swi-prolog-lite-${SWIPLVERS}nb1:../../lang/swi-prolog-lite
DEPENDS+=		swi-prolog-packages-${SWIPLVERS}nb1:../../lang/swi-prolog-packages

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_MTREE=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
