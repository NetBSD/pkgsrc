# $NetBSD: Makefile,v 1.2 2000/06/01 11:23:33 rh Exp $
#

DISTNAME=	japhar-0.08
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.japhar.org/pub/hungry/japhar/source/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.japhar.org/

ONLY_FOR_PLATFORM=	SunOS-*-*       # untested on NetBSD

GNU_CONFIGURE=	yes
USE_PKGLIBTOOL=	yes
LIBTOOL_FLAGS=	--install-la
USE_GMAKE=	yes

.include "../../mk/bsd.prefs.mk"

# The japhar tar archive uses ././@LongLink GNU tar hacks
.undef EXTRACT_USING_PAX

.include "../../mk/bsd.pkg.mk"
