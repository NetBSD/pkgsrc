# $NetBSD: Makefile,v 1.10 2003/12/27 04:05:08 grant Exp $

DISTNAME=	libdvdread-0.9.4
CATEGORIES=	misc
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD access library, primarily used in Ogle

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_BUILDLINK2=	yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

MESSAGE_SUBST+=	PKGBASE=${PKGBASE}

.include "../../mk/bsd.pkg.mk"
