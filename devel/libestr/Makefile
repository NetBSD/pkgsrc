# $NetBSD: Makefile,v 1.3 2020/01/26 17:30:59 rillig Exp $
#

DISTNAME=		libestr-0.1.10
CATEGORIES=		devel
MASTER_SITES=		http://libestr.adiscon.com/files/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://libestr.adiscon.com/
COMMENT=		Library for some string essentials
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libestr.pc.in

.include "../../mk/bsd.pkg.mk"
