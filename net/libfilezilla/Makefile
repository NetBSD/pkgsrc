# $NetBSD: Makefile,v 1.24 2019/08/16 09:40:06 wiz Exp $

DISTNAME=	libfilezilla-0.18.1
CATEGORIES=	devel
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
GCC_REQD+=	7

BUILDLINK_API_DEPENDS.nettle+=	nettle>=3.1
.include "../../security/nettle/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.5.7
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
