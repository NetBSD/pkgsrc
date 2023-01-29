# $NetBSD: Makefile,v 1.33 2023/01/29 21:16:30 ryoon Exp $
#

DISTNAME=	extrema-4.4.5
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=extrema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://exsitewebware.com/extrema/
COMMENT=	Visualization and data analysis tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--with-wxGTK

# \todo Test with wxGTK30 and switch.
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
