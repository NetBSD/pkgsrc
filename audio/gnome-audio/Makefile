# $NetBSD: Makefile,v 1.19 2008/04/26 00:56:05 wiz Exp $
#

DISTNAME=	gnome-audio-2.22.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-audio/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of audio files for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
