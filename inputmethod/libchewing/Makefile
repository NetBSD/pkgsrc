# $NetBSD: Makefile,v 1.8 2013/08/10 09:14:22 obache Exp $
#

DISTNAME=	libchewing-0.3.5
CATEGORIES=	chinese inputmethod
MASTER_SITES=	http://chewing.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://chewing.im/
COMMENT=	The intelligent phonetic input method library
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	yes

PKGCONFIG_OVERRIDE=	chewing.pc.in

.include "../../mk/bsd.pkg.mk"
