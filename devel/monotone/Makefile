# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:31 tv Exp $
#

DISTNAME=		monotone-0.14
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		http://www.venge.net/monotone/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.venge.net/monotone/
COMMENT=		Distributed revision control system

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--with-bundled-lua=no
CONFIGURE_ARGS+=	--with-bundled-sqlite=no

# XXX need rules for other compilers
BUILD_ENV+=	BLIBSF="-gcc"

# XXX This pkg doesn't need threads. Just the "configure"
# script is too stupid (it adds -pthread to CFLAGS).
.include "../../devel/boost-thread/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
