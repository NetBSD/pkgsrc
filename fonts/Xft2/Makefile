# $NetBSD: Makefile,v 1.7 2003/03/09 06:13:53 jmc Exp $
#

DISTNAME=	fcpackage.2_1
PKGNAME=	Xft2-2.1
PKGREVISION=	4
CATEGORIES=	fonts x11
MASTER_SITES=	http://fontconfig.org/release/

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Library for configuring and customizing font access

# This can use 2.0.5 but things which use it (ala pango) require 2.0.9 so make
# sure to keep in step
BUILDLINK_DEPENDS.freetype2?=  freetype2>=2.0.9

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}/Xft

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
