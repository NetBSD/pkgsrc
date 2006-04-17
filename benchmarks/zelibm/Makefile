# $NetBSD: Makefile,v 1.5 2006/04/17 13:46:17 wiz Exp $
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

.include "../../mk/x11.buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
