# $NetBSD: Makefile,v 1.11 2004/04/26 05:33:04 snj Exp $
#

DISTNAME=	pan-0.11.4
PKGREVISION=	8
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
