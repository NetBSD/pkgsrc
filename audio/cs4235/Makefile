# $NetBSD: Makefile,v 1.6 2004/01/20 12:07:41 agc Exp $
#

DISTNAME=	cs4235-20001009
CATEGORIES=	audio sysutils
MASTER_SITES=	http://invisible.yi.org/~jmcneill/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://invisible.yi.org/~jmcneill/
COMMENT=	Modifies the 3D mode on Crystal CS4235 sound cards

ONLY_FOR_PLATFORM= NetBSD-*-i386

WRKSRC=		${WRKDIR}/cs4235

MAKE_ENV+=	BINDIR=${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
