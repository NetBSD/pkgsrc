# $NetBSD: Makefile,v 1.1.1.1 2003/01/03 05:37:33 rh Exp $
#

DISTNAME=	gnustep-1.5.1
CATEGORIES=	meta-pkgs x11 gnustep
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	meta-package for GNUstep

DEPENDS+=	gnustep-examples>0.9.7:../../devel/gnustep-examples
DEPENDS+=	gnustep-preferences>1.2.0:../../x11/gnustep-preferences
DEPENDS+=	ImageViewer-[0-9]*:../../graphics/ImageViewer
DEPENDS+=	3DKit-[0-9]*:../../graphics/3DKit
DEPENDS+=	GNUMail>1.0.3:../../mail/GNUMail

USE_X11=	yes
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
