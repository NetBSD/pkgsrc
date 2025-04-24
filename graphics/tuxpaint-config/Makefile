# $NetBSD: Makefile,v 1.31 2025/04/24 14:14:41 wiz Exp $

DISTNAME=		tuxpaint-config-0.0.25
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tuxpaint.org/
COMMENT=		Configuration program for tuxpaint
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake msgfmt pkg-config

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	MAN_PREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../textproc/libunibreak/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
