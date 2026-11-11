# $NetBSD: Makefile,v 1.3 2026/11/11 11:54:40 wiz Exp $

DISTNAME=	libimobiledevice-glue-1.3.3
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libimobiledevice/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libimobiledevice/libimobiledevice-glue
COMMENT=	Library with common code for the libimobiledevice project
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/libimobiledevice-glue-1.0.pc.in

.include "../../textproc/libplist/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
