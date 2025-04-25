# $NetBSD: Makefile,v 1.44 2025/04/25 10:42:29 wiz Exp $

DISTNAME=	vcdimager-2.0.1
PKGREVISION=	14
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=vcdimager/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/vcdimager/
COMMENT=	Mastering suite for Video CDs
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes
PKGCONFIG_OVERRIDE+=	libvcdinfo.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=libvcdinfo.la.ver
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
