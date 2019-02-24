# $NetBSD: Makefile,v 1.11 2019/02/24 10:35:48 wiz Exp $

DISTNAME=	spice-protocol-0.12.15
CATEGORIES=	sysutils
MASTER_SITES=	http://spice-space.org/download/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spice-space.org/
COMMENT=	Headers defining protocols for SPICE server code
LICENSE=	modified-bsd AND mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	spice-protocol.pc.in

.include "../../mk/bsd.pkg.mk"
