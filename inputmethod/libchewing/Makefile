# $NetBSD: Makefile,v 1.6 2012/10/06 14:25:14 asau Exp $
#

DISTNAME=	libchewing-0.3.3
CATEGORIES=	chinese inputmethod
MASTER_SITES=	http://chewing.csie.net/download/libchewing/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://chewing.csie.net/
COMMENT=	The intelligent phonetic input method library
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE=	chewing.pc.in

.include "../../mk/bsd.pkg.mk"
