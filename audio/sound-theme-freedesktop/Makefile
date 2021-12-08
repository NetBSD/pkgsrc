# $NetBSD: Makefile,v 1.15 2021/12/08 16:03:20 adam Exp $
#

DISTNAME=	sound-theme-freedesktop-0.8
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://cgit.freedesktop.org/sound-theme-freedesktop/snapshot/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Specifications/sound-theme-spec
COMMENT=	Set of audio files for FreeDesktop
#LICENSE=	# See -> grep License CREDITS

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool msgfmt autoconf automake

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

pre-configure:
	(cd ${WRKSRC} && autoreconf -i)

BUILDLINK_DEPMETHOD.glib2=	build

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
