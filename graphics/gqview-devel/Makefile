# $NetBSD: Makefile,v 1.86 2026/01/27 08:39:41 wiz Exp $

DISTNAME=	gqview-2.1.5
PKGREVISION=	48
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gqview.sourceforge.net/
COMMENT=	GTK2-based graphic file viewer (development version)

USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

MAKE_ENV+=		builddir=.

LDFLAGS+=		-lm
LDFLAGS.SunOS+=		-lm -lsocket -lnsl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
