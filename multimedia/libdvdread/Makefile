# $NetBSD: Makefile,v 1.6 2005/04/11 21:46:42 tv Exp $

DISTNAME=	libdvdread-0.9.4
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD access library, primarily used in Ogle

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes

MESSAGE_SUBST+=	PKGBASE=${PKGBASE}

.include "../../mk/bsd.pkg.mk"
