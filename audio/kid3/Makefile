# $NetBSD: Makefile,v 1.9 2007/11/30 21:55:04 wiz Exp $
#

DISTNAME=		kid3-0.8.1
PKGREVISION=		2
CATEGORIES=		kde audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kid3/}

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://kid3.sourceforge.net/
COMMENT=		KDE ID3 tagger

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

CHECK_PORTABILITY_SKIP+=	make_qtonly.sh

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libtunepimp/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
