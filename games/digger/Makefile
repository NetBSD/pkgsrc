# $NetBSD: Makefile,v 1.2 2004/03/06 20:35:30 snj Exp $
#

DISTNAME=		digger-20020314
CATEGORIES=		games
MASTER_SITES=		http://www.digger.org/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.digger.org/
COMMENT=		Digger Remastered

USE_BUILDLINK3=		yes

MAKEFILE=		Makefile.fbsd
MAKE_FLAGS+=		-DSDL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digger ${PREFIX}/bin/digger

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
