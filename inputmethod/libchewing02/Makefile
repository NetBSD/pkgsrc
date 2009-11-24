# $NetBSD: Makefile,v 1.1.1.1 2009/11/24 11:18:53 obache Exp $
#

DISTNAME=	libchewing-0.2.7
CATEGORIES=	chinese inputmethod
MASTER_SITES=	http://chewing.csie.net/download/libchewing/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://chewing.csie.net/
COMMENT=	The intelligent phonetic input method library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE=	chewing.pc.in

.include "../../mk/bsd.pkg.mk"
