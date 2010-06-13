# $NetBSD: Makefile,v 1.43 2010/06/13 22:44:44 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/sane-backends/Makefile.common"

DISTNAME=	sane-frontends-${SANE_VERSION}
SANE_MICRO=	14
PKGREVISION=	8

COMMENT=	Frontends for access to scanners, digital cameras, frame grabbers etc

BUILDLINK_API_DEPENDS.sane+=	sane-backends>=${SANE_VERSION}

USE_TOOLS+=	pkg-config

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
