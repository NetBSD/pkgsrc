# $NetBSD: Makefile,v 1.11 2004/01/24 14:11:10 grant Exp $

DISTNAME=	libdvdread-0.9.4
CATEGORIES=	misc
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD access library, primarily used in Ogle

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_BUILDLINK2=	yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

MESSAGE_SUBST+=	PKGBASE=${PKGBASE}

.include "../../mk/bsd.pkg.mk"
