# $NetBSD: Makefile,v 1.11 2008/08/02 16:46:56 dholland Exp $
#

DISTNAME=	cs4235-20001009
PKGREVISION=	1
CATEGORIES=	audio sysutils
MASTER_SITES=	http://www.invisible.ca/~jmcneill/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://www.invisible.ca/~jmcneill/
COMMENT=	Modifies the 3D mode on Crystal CS4235 sound cards

ONLY_FOR_PLATFORM= NetBSD-*-i386 NetBSD-*-x86_64

WRKSRC=		${WRKDIR}/cs4235
MAKE_ENV+=	${BSD_MAKE_ENV}

.include "../../mk/bsd.pkg.mk"
