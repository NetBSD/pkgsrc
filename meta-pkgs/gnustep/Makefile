# $NetBSD: Makefile,v 1.27 2009/04/13 12:47:43 rh Exp $

DISTNAME=	gnustep-2.0.8
CATEGORIES=	meta-pkgs x11 gnustep
MASTER_SITES=	# empty

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Meta-package for GNUstep

DEPENDS+=	gnustep-make>=2.0.8:../../devel/gnustep-make
DEPENDS+=	gnustep-base>=1.18.0:../../devel/gnustep-base
DEPENDS+=	gnustep-gui>=0.16.0:../../x11/gnustep-gui
DEPENDS+=	gnustep-back>=0.16.0:../../x11/gnustep-back
DEPENDS+=	gnustep-examples>=1.2.0:../../devel/gnustep-examples
DEPENDS+=	ImageViewer>=0.6.3nb7:../../graphics/ImageViewer
DEPENDS+=	GNUMail>=1.1.2nb2:../../mail/GNUMail
DEPENDS+=	Gorm>=1.2.8:../../devel/Gorm
DEPENDS+=	ProjectCenter>=0.5.0:../../devel/ProjectCenter
DEPENDS+=	Renaissance>=0.9.0:../../devel/Renaissance
DEPENDS+=	gworkspace>=0.8.6:../../sysutils/gworkspace

META_PACKAGE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
