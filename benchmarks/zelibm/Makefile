# $NetBSD: Makefile,v 1.4 2006/03/04 21:29:01 jlam Exp $
#

DISTNAME=		zelibm
PKGNAME=		zelibm-0
PKGREVISION=		1
CATEGORIES=		benchmarks
MASTER_SITES=		http://people.redhat.com/drepper/libm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://people.redhat.com/drepper/libm/
COMMENT=		Visual Math Library Quality Check

USE_TOOLS+=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libmtest ${PREFIX}/bin

.include "../../mk/x11.buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
