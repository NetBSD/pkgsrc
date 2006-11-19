# $NetBSD: Makefile,v 1.2 2006/11/19 11:50:24 wiz Exp $
#

DISTNAME=		libofa-0.9.3
PKGREVISION=		1
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
