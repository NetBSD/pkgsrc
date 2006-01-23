# $NetBSD: Makefile,v 1.9 2006/01/23 22:09:26 wiz Exp $

DISTNAME=	libdvdread-0.9.5
CATEGORIES=	multimedia
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD access library, primarily used in Ogle

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

MESSAGE_SUBST+=	PKGBASE=${PKGBASE:Q}

.include "../../mk/bsd.pkg.mk"
