# $NetBSD: Makefile,v 1.16 2012/09/11 22:37:15 asau Exp $
#

DISTNAME=		zelibm
PKGNAME=		zelibm-0
PKGREVISION=		9
CATEGORIES=		benchmarks
MASTER_SITES=		http://people.redhat.com/drepper/libm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://people.redhat.com/drepper/libm/
COMMENT=		Visual Math Library Quality Check

INSTALLATION_DIRS=	bin

USE_TOOLS+=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libmtest ${DESTDIR}${PREFIX}/bin

.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
