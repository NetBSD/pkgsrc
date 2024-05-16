# $NetBSD: Makefile,v 1.58 2024/05/16 06:15:20 wiz Exp $

DISTNAME=	libfilezilla-0.47.0
PKGREVISION=	1
CATEGORIES=	net
# some kind of direct-download disabling
#MASTER_SITES=	https://dl3.cdn.filezilla-project.org/libfilezilla/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lib.filezilla-project.org/
COMMENT=	Library for building high-performing, platform-independent programs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake msgfmt pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES=	c++17
# NetBSD 9's gcc 7 is not good enough
GCC_REQD+=		8

PKGCONFIG_OVERRIDE+=	lib/libfilezilla.pc.in

# https://trac.filezilla-project.org/ticket/13087
BUILDLINK_TRANSFORM+=	rm:-ldl
DL_AUTO_VARS=		yes

BUILDLINK_API_DEPENDS.nettle+=	nettle>=3.1
.include "../../security/nettle/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.5.7
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
