# $NetBSD: Makefile,v 1.3 2004/10/03 00:14:43 tv Exp $
#

DISTNAME=		digger-20020314
PKGREVISION=	1
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
