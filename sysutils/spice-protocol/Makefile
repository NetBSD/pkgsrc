# $NetBSD: Makefile,v 1.4 2015/08/06 11:07:30 wiz Exp $

DISTNAME=	spice-protocol-0.12.9
CATEGORIES=	sysutils
MASTER_SITES=	http://spice-space.org/download/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://spice-space.org/
COMMENT=	Headers defining protocols for SPICE server code
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	spice-protocol.pc.in

.include "../../mk/bsd.pkg.mk"
