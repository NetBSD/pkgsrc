# $NetBSD: Makefile,v 1.16 2004/10/03 00:12:58 tv Exp $
#

DISTNAME=	gnustep-1.10.0
PKGREVISION=	2
CATEGORIES=	meta-pkgs x11 gnustep
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Meta-package for GNUstep

DEPENDS+=	gnustep-make>=1.10.0:../../devel/gnustep-make
DEPENDS+=	gnustep-base>=1.10.0:../../devel/gnustep-base
DEPENDS+=	gnustep-ssl>=1.10.0:../../security/gnustep-ssl
DEPENDS+=	gnustep-gui>=0.9.4:../../x11/gnustep-gui
DEPENDS+=	gnustep-back>=0.9.4:../../x11/gnustep-back
DEPENDS+=	gnustep-examples>=1.0.0:../../devel/gnustep-examples
DEPENDS+=	ImageViewer>=0.6.2:../../graphics/ImageViewer
DEPENDS+=	GNUMail>=1.1.2nb2:../../mail/GNUMail
DEPENDS+=	Gorm>=0.8.0:../../devel/Gorm
DEPENDS+=	ProjectCenter>=0.3.6:../../devel/ProjectCenter
DEPENDS+=	Renaissance>=0.7.0:../../devel/Renaissance
DEPENDS+=	gworkspace>=0.6.3:../../sysutils/gworkspace

USE_X11=	yes
USE_BUILDLINK3=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes
EXTRACT_ONLY=	# empty

do-install:	# empty

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
