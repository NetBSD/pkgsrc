# $NetBSD: Makefile,v 1.10 2011/11/01 06:02:01 sbd Exp $

DISTNAME=	fityk-0.9.7
PKGREVISION=	2
CATEGORIES=	math
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fityk/}
MASTER_SITES=	https://cloud.github.com/downloads/wojdyr/fityk/
FETCH_USING=	curl
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fityk.sourceforge.net/
COMMENT=	Peak fitting software
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
# XXX: xyconvert requires wxWidgets >= 2.9
CONFIGURE_ARGS+=	--disable-xyconvert

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../math/xylib/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
