# $NetBSD: Makefile,v 1.2 2006/08/22 14:32:11 joerg Exp $
#

DISTNAME=		kid3-0.7
CATEGORIES=		kde audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kid3/}

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://kid3.sourceforge.net/
COMMENT=		KDE ID3 tagger

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++

# Note: put app specific data files into kde dir
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/kde

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libtunepimp0.4/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
