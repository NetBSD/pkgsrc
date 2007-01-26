# $NetBSD: Makefile,v 1.6 2007/01/26 21:56:40 joerg Exp $
#

DISTNAME=		zelibm
PKGNAME=		zelibm-0
PKGREVISION=		2
CATEGORIES=		benchmarks
MASTER_SITES=		http://people.redhat.com/drepper/libm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://people.redhat.com/drepper/libm/
COMMENT=		Visual Math Library Quality Check

USE_TOOLS+=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libmtest ${PREFIX}/bin

.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
