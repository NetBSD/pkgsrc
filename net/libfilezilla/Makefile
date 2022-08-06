# $NetBSD: Makefile,v 1.43 2022/08/06 00:40:08 gutteridge Exp $

DISTNAME=	libfilezilla-0.38.1
CATEGORIES=	net
# some kind of direct-download disabling
#MASTER_SITES=	https://dl3.cdn.filezilla-project.org/libfilezilla/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lib.filezilla-project.org/
COMMENT=	Library for building high-performing, platform-independent programs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake msgfmt pkg-config
USE_LANGUAGES=	c c++17

PKGCONFIG_OVERRIDE+=	lib/libfilezilla.pc.in

# for C++17
GCC_REQD+=	8

BUILDLINK_API_DEPENDS.nettle+=	nettle>=3.1
.include "../../security/nettle/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.5.7
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
# As of 0.19, 64-bit atomic ops are required
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
