# $NetBSD: Makefile,v 1.1.1.1 2005/07/27 17:06:53 drochner Exp $
#

DISTNAME=		zelibm
PKGNAME=		zelibm-0
CATEGORIES=		benchmarks
MASTER_SITES=		http://people.redhat.com/drepper/libm/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://people.redhat.com/drepper/libm/
COMMENT=		Visual Math Library Quality Check

USE_TOOLS+=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libmtest ${PREFIX}/bin

.include "../../mk/x11.buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
