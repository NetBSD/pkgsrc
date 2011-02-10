# $NetBSD: Makefile,v 1.7 2011/02/10 21:49:48 zafer Exp $
#

DISTNAME=		libofa-0.9.3
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://distfiles.aydogan.net/audio/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.musicip.com/dns/index.jsp
COMMENT=		Open Fingerprint Architecture library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libofa.pc.in

.include "../../math/fftw/buildlink3.mk"
# next two only needed for examples
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
