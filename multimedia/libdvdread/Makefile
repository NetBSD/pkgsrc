# $NetBSD: Makefile,v 1.3 2004/02/14 17:21:45 jlam Exp $

DISTNAME=	libdvdread-0.9.4
CATEGORIES=	multimedia
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD access library, primarily used in Ogle

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_BUILDLINK3=	yes

MESSAGE_SUBST+=	PKGBASE=${PKGBASE}

.include "../../mk/bsd.pkg.mk"
