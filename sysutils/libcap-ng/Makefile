# $NetBSD$

DISTNAME=	libcap-ng-0.7.9
CATEGORIES= sysutils
MASTER_SITES=	http://people.redhat.com/sgrubb/libcap-ng/

MAINTAINER=	gang65@poczta.onet.pl
HOMEPAGE=	http://people.redhat.com/sgrubb/libcap-ng/
COMMENT=	Library for getting and setting POSIX.1e capabilities
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/libcap-ng.pc.in


.include "../../mk/bsd.pkg.mk"
