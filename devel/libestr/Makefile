# $NetBSD: Makefile,v 1.2 2015/01/16 16:40:45 fhajny Exp $
#

DISTNAME=		libestr-0.1.10
CATEGORIES=		devel
MASTER_SITES=		http://libestr.adiscon.com/files/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://libestr.adiscon.com/
COMMENT=		Library for some string essentials
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libestr.pc.in

.include "../../mk/bsd.pkg.mk"
