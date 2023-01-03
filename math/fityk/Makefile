# $NetBSD: Makefile,v 1.47 2023/01/03 17:37:49 wiz Exp $

DISTNAME=	fityk-0.9.7
PKGREVISION=	32
CATEGORIES=	math
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fityk/}
MASTER_SITES=	https://cloud.github.com/downloads/wojdyr/fityk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fityk.nieto.pl/
COMMENT=	Peak fitting software
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
# XXX: xyconvert requires wxWidgets >= 2.9
CONFIGURE_ARGS+=	--disable-xyconvert

CFLAGS.FreeBSD+=	-D_WITH_GETLINE

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../math/xylib/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
