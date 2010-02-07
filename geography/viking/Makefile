# $NetBSD: Makefile,v 1.10 2010/02/07 15:54:33 gdt Exp $
#

DISTNAME=		viking-0.9.91
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=viking/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://viking.sourceforge.net/
COMMENT=		Viking manages GPS data, supports Open Street Map and geocaching

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

# Perhaps optionize use of gpsd (remove bl3, add this).
# CONFIGURE_ARGS+=	--disable-realtime-gps-tracking

DEPENDS+=		gpsbabel-[0-9]*:../../geography/gpsbabel
REPLACE_PERL=		viking-remote

USE_TOOLS+=		gmake intltool msgfmt pkg-config


.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
