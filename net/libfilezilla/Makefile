# $NetBSD: Makefile,v 1.42 2022/07/21 11:31:23 wiz Exp $

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

# As of 0.19, 64-bit atomic ops are required
.if ${MACHINE_ARCH} == "i386"
CXXFLAGS+=	-march=i586
.endif

BUILDLINK_API_DEPENDS.nettle+=	nettle>=3.1
.include "../../security/nettle/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.5.7
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
