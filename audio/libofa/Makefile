# $NetBSD: Makefile,v 1.1.1.1 2006/07/12 13:12:57 wiz Exp $
#

DISTNAME=		libofa-0.9.3
CATEGORIES=		audio
MASTER_SITES=		http://www.musicdns.org/themes/musicdns_org/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.musicdns.org/
COMMENT=		Open Fingerprint Architecture library

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
