# $NetBSD: Makefile,v 1.13 2010/06/13 22:43:54 wiz Exp $
#

DISTNAME=		zelibm
PKGNAME=		zelibm-0
PKGREVISION=		7
CATEGORIES=		benchmarks
MASTER_SITES=		http://people.redhat.com/drepper/libm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://people.redhat.com/drepper/libm/
COMMENT=		Visual Math Library Quality Check

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

USE_TOOLS+=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libmtest ${DESTDIR}${PREFIX}/bin

.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
