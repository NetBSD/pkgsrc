# $NetBSD: Makefile,v 1.1.1.1 2003/04/15 10:26:35 wiz Exp $
#

DISTNAME=	pan-0.11.4
PKGREVISION=	2
CATEGORIES=	news gnome
MASTER_SITES=	http://pan.rebelbase.com/download/releases/${DISTNAME:C/pan-//}/SOURCE/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://pan.rebelbase.com/
COMMENT=	Newsreader for Gnome

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALEDIR="${PKGLOCALEDIR}"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "SunOS"
LIBS=			-lcompat
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
