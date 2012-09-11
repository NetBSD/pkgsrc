# $NetBSD: Makefile,v 1.16 2012/09/11 23:59:29 asau Exp $
#

DISTNAME=	cs4235-20001009
PKGREVISION=	1
CATEGORIES=	audio sysutils
MASTER_SITES=	http://distfiles.aydogan.net/audio/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.invisible.ca/~jmcneill/
COMMENT=	Modifies the 3D mode on Crystal CS4235 sound cards
LICENSE=	public-domain

INSTALLATION_DIRS=	bin

ONLY_FOR_PLATFORM= NetBSD-*-i386 NetBSD-*-x86_64

WRKSRC=		${WRKDIR}/cs4235
MAKE_ENV+=	${BSD_MAKE_ENV}

.include "../../mk/bsd.pkg.mk"
