# $NetBSD: Makefile,v 1.7 2017/05/29 10:24:02 wiz Exp $

DISTNAME=	mdds-1.2.3
PKGNAME=	${DISTNAME:S/mdds/mdds1.2/}
CATEGORIES=	devel
MASTER_SITES=	http://kohei.us/files/mdds/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/mdds/mdds
COMMENT=	Collection of multi-dimensional data structure and indexing algorithms (1.2 branch)
LICENSE=	mit

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	misc/mdds.pc.in

CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/mdds-1.2

BUILDLINK_DEPMETHOD.boost-headers?=	build
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
