# $NetBSD: Makefile,v 1.15 2003/09/19 01:56:45 grant Exp $
#

DISTNAME=	fcpackage.2_1
PKGNAME=	Xft2-2.1
PKGREVISION=	4
WRKSRC=		${WRKDIR}/${DISTNAME}/Xft
CATEGORIES=	fonts x11
MASTER_SITES=	http://fontconfig.org/release/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Library for configuring and customizing font access

# This can use 2.0.5 but things which use it (ala pango) require 2.0.9 so make
# sure to keep in step
BUILDLINK_DEPENDS.freetype2=  freetype2>=2.0.9

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	awk

.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
