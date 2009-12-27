# $NetBSD: Makefile,v 1.7 2009/12/27 16:43:56 gdt Exp $
#

DISTNAME=		viking-0.9.9
PKGREVISION=		2
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=viking/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://viking.sourceforge.net/
COMMENT=		Viking manages GPS data, supports Open Street Map and geocaching

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

# gpsd withdrew an interface viking still uses
CONFIGURE_ARGS+=	--disable-realtime-gps-tracking

DEPENDS+=		gpsbabel-[0-9]*:../../geography/gpsbabel
REPLACE_PERL=		viking-remote

USE_TOOLS+=		gmake intltool msgfmt pkg-config


.include "../../devel/gettext-lib/buildlink3.mk"
# viking uses an interface withdrawn in gpsd 2.90.  Locally revert
# gpsd or fix viking upstream.  gdt, 20091227
# https://sourceforge.net/tracker/?func=detail&aid=2921899&group_id=83870&atid=570954
#.include "../../geography/gpsd/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
