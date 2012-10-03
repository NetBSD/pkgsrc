# $NetBSD: Makefile,v 1.54.2.1 2012/10/03 12:08:14 spz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/sane-backends/Makefile.common"

DISTNAME=	sane-frontends-${SANE_VERSION}
SANE_MICRO=	14
PKGREVISION=	20

COMMENT=	Frontends for access to scanners, digital cameras, frame grabbers etc

BUILDLINK_API_DEPENDS.sane+=	sane-backends>=${SANE_VERSION}

USE_TOOLS+=	pkg-config

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
