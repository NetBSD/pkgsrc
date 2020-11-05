# $NetBSD: Makefile,v 1.48 2020/11/05 09:08:38 ryoon Exp $

DISTNAME=	gnustep-2.6.2
PKGREVISION=	19
CATEGORIES=	meta-pkgs x11 gnustep
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	Meta-package for GNUstep

DEPENDS+=	gnustep-make>=2.6.2:../../devel/gnustep-make
DEPENDS+=	gnustep-base>=1.24.0:../../devel/gnustep-base
DEPENDS+=	gnustep-gui>=0.22.0:../../x11/gnustep-gui
DEPENDS+=	gnustep-back>=0.22.0:../../x11/gnustep-back
DEPENDS+=	gnustep-examples>=1.3.0nb1:../../devel/gnustep-examples
DEPENDS+=	ImageViewer>=0.6.3nb7:../../graphics/ImageViewer
DEPENDS+=	GNUMail>=1.2.0:../../mail/GNUMail
DEPENDS+=	Gorm>=1.2.18:../../devel/Gorm
DEPENDS+=	ProjectCenter>=0.6.1:../../devel/ProjectCenter
DEPENDS+=	Renaissance>=0.9.0:../../devel/Renaissance
DEPENDS+=	gworkspace>=0.9.1:../../sysutils/gworkspace

META_PACKAGE=	yes

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
