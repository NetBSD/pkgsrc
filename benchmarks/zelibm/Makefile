# $NetBSD: Makefile,v 1.34 2024/07/11 19:53:33 wiz Exp $
#

DISTNAME=		zelibm
PKGNAME=		zelibm-0
PKGREVISION=		26
CATEGORIES=		benchmarks
MASTER_SITES=		https://akkadia.org/drepper/libm/

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
