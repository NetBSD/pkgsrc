# $NetBSD: Makefile,v 1.19 2018/12/09 03:04:34 sevan Exp $

DISTNAME=	libfilezilla-0.15.1
CATEGORIES=	devel
#MASTER_SITES=	https://dl2.cdn.filezilla-project.org/libfilezilla/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lib.filezilla-project.org/
COMMENT=	Library for building high-performing, platform-independent programs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	lib/libfilezilla.pc.in

# GCC 4.9 is required to support C++14
GCC_REQD+=	4.9

BUILDLINK_API_DEPENDS.nettle+=	nettle>=3.1
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
