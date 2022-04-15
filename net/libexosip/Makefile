# $NetBSD: Makefile,v 1.9 2022/04/15 12:43:32 schwarz Exp $

DISTNAME=	libexosip2-5.3.0
PKGNAME=	${DISTNAME:S/exosip/eXosip/1}
CATEGORIES=	net devel
MASTER_SITES=	https://download.savannah.nongnu.org/releases/exosip/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/exosip
COMMENT=	The Extended Open SIP library
LICENSE=	gnu-gpl-v2

DEPENDS+=	libexosip>=${PKGVERSION_NOREV}:../../devel/libosip

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_FEATURES+=	getopt_long

LIBS.SunOS+=	-lsocket -lnsl
LIBS.Darwin+=	-framework CoreServices -framework Security

.include "options.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
