# $NetBSD: Makefile,v 1.1.1.1 2002/12/16 12:08:42 jmmv Exp $
#

DISTNAME=	fcpackage.2_1
PKGNAME=	Xft2-2.1
CATEGORIES=	fonts x11
MASTER_SITES=	http://fontconfig.org/release/

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Library for configuring and customizing font access

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}/Xft

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
