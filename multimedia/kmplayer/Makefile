# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 12:10:13 jmmv Exp $
#

DISTNAME=	kmplayer-0.8.2rc5
PKGREVISION=	2
CATEGORIES=	multimedia kde
MASTER_SITES=	http://www.xs4all.nl/~jjvrieze/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	murray@river-styx.org
HOMEPAGE=	http://www.xs4all.nl/~jjvrieze/
COMMENT=	KDE frontend to mplayer

BUILD_USES_MSGFMT=	yes
DEPENDS=		mplayer>=1.0rc3:../../multimedia/mplayer
DEPENDS+=		mencoder>=1.0rc3:../../multimedia/mencoder
DEPENDS+=		xine-arts>=1rc0a:../../audio/xine-arts

WRKSRC=			${WRKDIR}/kmplayer
GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PERL5=		build

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xine-lib/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
