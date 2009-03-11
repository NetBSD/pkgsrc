# $NetBSD: Makefile,v 1.1.1.1 2009/03/11 14:18:30 gdt Exp $
#

DISTNAME=		viking-0.9.8
CATEGORIES=		geography
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=viking/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://viking.sourceforge.net/
COMMENT=		Viking manages GPS data, supports Open Street Map and geocaching

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

DEPENDS+=		gpsbabel-[0-9]*:../../geography/gpsbabel
REPLACE_PERL=		viking-remote

USE_TOOLS+=		intltool
USE_TOOLS+=		gmake
USE_TOOLS+=		msgfmt

USE_DIRS+=		xdg-1.4

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
