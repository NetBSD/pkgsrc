# $NetBSD: Makefile,v 1.4 2003/05/02 11:55:46 wiz Exp $
#

DISTNAME=	gnustep-1.6.0
PKGREVISION=	1
CATEGORIES=	meta-pkgs x11 gnustep
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	meta-package for GNUstep

DEPENDS+=	gnustep-examples>0.9.7:../../devel/gnustep-examples
DEPENDS+=	gnustep-preferences>=1.2.0nb2:../../x11/gnustep-preferences
DEPENDS+=	ImageViewer-[0-9]*:../../graphics/ImageViewer
DEPENDS+=	3DKit-[0-9]*:../../graphics/3DKit
DEPENDS+=	GNUMail>1.0.3:../../mail/GNUMail
DEPENDS+=	Gorm>=0.2.0:../../devel/Gorm

USE_X11=	yes
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
