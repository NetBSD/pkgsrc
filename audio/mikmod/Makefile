# $NetBSD: Makefile,v 1.20 2000/04/02 16:32:34 pooka Exp $
#

DISTNAME=	mikmod-3.1.6-a
PKGNAME=	mikmod-3.1.6a
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.darkorb.net/libmikmod/

MAINTAINER=	mycroft@NetBSD.ORG
HOMEPAGE=	http://mikmod.darkorb.net/

DEPENDS+=	ncurses>=4.2:../../devel/ncurses
DEPENDS+=	libmikmod>=3.1.9:../../audio/libmikmod

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
