# $NetBSD: Makefile,v 1.31 2012/02/09 21:44:28 sbd Exp $

DISTNAME=	qalculate-kde-0.9.5
PKGREVISION=	15
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qalculate/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qalculate.sourceforge.net/
COMMENT=	Modern multi-purpose desktop calculator (KDE version)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=	wget>=1.8:../../net/wget

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gmake msgfmt pkg-config perl
GNU_CONFIGURE=		yes
SET_LIBDIR=		yes

pre-configure:
	${RUN} cd ${WRKSRC}; autoconf

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
