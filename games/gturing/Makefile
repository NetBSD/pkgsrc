# $NetBSD: Makefile,v 1.46 2009/08/26 19:57:31 sno Exp $
#

DISTNAME=		gturing-0.1.1
PKGREVISION=		26
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gturing/0.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 turing machine emulator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES

BUILDLINK_TRANSFORM+=	rm:-D.*_DISABLE_DEPRECATED

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
