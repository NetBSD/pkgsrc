# $NetBSD: Makefile,v 1.3 2014/07/12 16:48:26 schwarz Exp $

DISTNAME=	libeXosip2-4.1.0
CATEGORIES=	devel net
MASTER_SITES=	http://download.savannah.nongnu.org/releases/exosip/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/exosip
COMMENT=	The Extended Open SIP library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_FEATURES+=	getopt_long

.include "options.mk"

LIBS.SunOS+=	-lsocket -lnsl
LIBS.Darwin+=	-framework CoreServices -framework Security

.include "../../net/libcares/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
