# $NetBSD: Makefile,v 1.12 2004/10/03 00:18:03 tv Exp $
#

DISTNAME=	pan-0.11.4
PKGREVISION=	9
CATEGORIES=	news gnome
MASTER_SITES=	http://pan.rebelbase.com/download/releases/${DISTNAME:C/pan-//}/SOURCE/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://pan.rebelbase.com/
COMMENT=	Newsreader for Gnome

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALEDIR="${PKGLOCALEDIR}"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "SunOS"
LIBS=			-lcompat
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
