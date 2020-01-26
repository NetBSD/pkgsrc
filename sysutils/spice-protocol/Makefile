# $NetBSD: Makefile,v 1.13 2020/01/26 17:32:11 rillig Exp $

DISTNAME=	spice-protocol-0.14.0
CATEGORIES=	sysutils
MASTER_SITES=	http://spice-space.org/download/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://spice-space.org/
COMMENT=	Headers defining protocols for SPICE server code
LICENSE=	modified-bsd AND mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	spice-protocol.pc.in

.include "../../mk/bsd.pkg.mk"
