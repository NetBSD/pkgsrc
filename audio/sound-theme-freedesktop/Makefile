# $NetBSD: Makefile,v 1.2 2008/12/15 10:43:13 hasso Exp $
#

DISTNAME=	sound-theme-freedesktop-0.2
CATEGORIES=	audio
MASTER_SITES=	http://people.freedesktop.org/~mccann/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Specifications/sound-theme-spec
COMMENT=	Set of audio files for FreeDesktop

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	gmake intltool msgfmt

.include "../../mk/bsd.pkg.mk"
