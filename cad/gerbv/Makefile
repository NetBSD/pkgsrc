# $NetBSD: Makefile,v 1.91 2025/12/21 07:44:13 wiz Exp $

DISTNAME=	gerbv-2.6.2
PKGREVISION=	21
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gerbv.github.io/
COMMENT=	Gerber file viewer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config

PLIST_SUBST+=	PKGNAME_NOREV=${PKGNAME_NOREV}

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
