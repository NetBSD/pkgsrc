# $NetBSD: Makefile,v 1.26 2008/01/18 05:08:32 tnn Exp $

DISTNAME=	gnustep-1.11.2
PKGREVISION=	4
CATEGORIES=	meta-pkgs x11 gnustep
MASTER_SITES=	# empty

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

META_PACKAGE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
