# $NetBSD: Makefile,v 1.1.1.1 1999/10/28 09:51:43 agc Exp $
#

DISTNAME=	japhar-0.08
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.japhar.org/pub/hungry/japhar/source/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.japhar.org/

ONLY_FOR_PLATFORM=	SunOS-*-*       # untested on NetBSD

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LIBTOOL_FLAGS=	--install-la
USE_GMAKE=	yes

.include "../../mk/bsd.prefs.mk"

# The japhar tar archive uses ././@LongLink GNU tar hacks
.undef EXTRACT_USING_PAX

.include "../../mk/bsd.pkg.mk"
