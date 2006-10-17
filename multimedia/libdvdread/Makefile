# $NetBSD: Makefile,v 1.16 2006/10/17 16:41:10 drochner Exp $

DISTNAME=	libdvdread-0.9.7
CATEGORIES=	multimedia
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD access library, primarily used in Ogle

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

MESSAGE_SUBST+=	PKGBASE=${PKGBASE:Q}

.include "../../mk/bsd.pkg.mk"
