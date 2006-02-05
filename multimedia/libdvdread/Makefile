# $NetBSD: Makefile,v 1.11 2006/02/05 23:10:16 joerg Exp $

DISTNAME=	libdvdread-0.9.5
PKGREVISION=	2
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
