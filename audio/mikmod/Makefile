# $NetBSD: Makefile,v 1.22 2001/01/07 02:47:02 wiz Exp $
#

DISTNAME=	mikmod-3.1.6-a
PKGNAME=	mikmod-3.1.6a
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.darkorb.net/mikmod/

MAINTAINER=	mycroft@NetBSD.ORG
HOMEPAGE=	http://mikmod.darkorb.net/

DEPENDS+=	libmikmod>=3.1.9:../../audio/libmikmod

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_CURSES=	yes
REPLACE_NCURSES=	${WRKSRC}/configure

CPPFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
