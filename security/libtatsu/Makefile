# $NetBSD: Makefile,v 1.5 2026/11/15 19:45:00 wiz Exp $

DISTNAME=	libtatsu-1.1.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=libimobiledevice/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libimobiledevice/libtatsu/
COMMENT=	Library handling the communication with Apple's Tatsu Signing Server
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/libtatsu-1.0.pc.in

.include "../../textproc/libplist/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
