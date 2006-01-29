# $NetBSD: Makefile,v 1.20 2006/01/29 21:33:02 adam Exp $

DISTNAME=	gnustep-1.11.2
CATEGORIES=	meta-pkgs x11 gnustep
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Meta-package for GNUstep

DEPENDS+=	gnustep-make>=1.11.2:../../devel/gnustep-make
DEPENDS+=	gnustep-base>=1.11.2:../../devel/gnustep-base
DEPENDS+=	gnustep-gui>=0.10.2:../../x11/gnustep-gui
DEPENDS+=	gnustep-back>=0.10.2:../../x11/gnustep-back
DEPENDS+=	gnustep-examples>=1.0.0:../../devel/gnustep-examples
DEPENDS+=	ImageViewer>=0.6.3:../../graphics/ImageViewer
DEPENDS+=	GNUMail>=1.1.2nb2:../../mail/GNUMail
DEPENDS+=	Gorm>=1.0.4:../../devel/Gorm
DEPENDS+=	ProjectCenter>=0.4.3:../../devel/ProjectCenter
DEPENDS+=	Renaissance>=0.8.0:../../devel/Renaissance
DEPENDS+=	gworkspace>=0.7.1:../../sysutils/gworkspace

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes
EXTRACT_ONLY=	# empty

do-install:	# empty

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
