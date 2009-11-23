# $NetBSD: Makefile,v 1.4 2009/11/23 11:57:36 drochner Exp $
#

DISTNAME=	sound-theme-freedesktop-0.7
CATEGORIES=	audio
MASTER_SITES=	http://cgit.freedesktop.org/sound-theme-freedesktop/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Specifications/sound-theme-spec
COMMENT=	Set of audio files for FreeDesktop

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool msgfmt autoconf automake

pre-configure:
	(cd ${WRKSRC} && autoreconf -i)

.include "../../mk/bsd.pkg.mk"
