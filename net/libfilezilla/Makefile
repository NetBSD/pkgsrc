# $NetBSD: Makefile,v 1.22 2019/07/20 22:46:39 wiz Exp $

DISTNAME=	libfilezilla-0.17.1
PKGREVISION=	1
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
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	lib/libfilezilla.pc.in

# TODO: update GCC_REQD, as of 0.17.1 this requires C++17
# GCC 4.9 is required to support C++14
GCC_REQD+=	4.9

BUILDLINK_API_DEPENDS.nettle+=	nettle>=3.1
.include "../../security/nettle/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.5.7
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
