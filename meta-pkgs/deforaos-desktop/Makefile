# $NetBSD: Makefile,v 1.11 2016/02/23 00:15:14 khorben Exp $
#

DISTNAME=	deforaos-desktop-0.0.11
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	Meta-package for the DeforaOS Desktop environment
LICENSE=	gnu-gpl-v3

META_PACKAGE=	yes

DEPENDS+=	deforaos-browser>=0.5.0:../../sysutils/deforaos-browser
DEPENDS+=	deforaos-camera>=0.2.0:../../graphics/deforaos-camera
DEPENDS+=	deforaos-coder>=0.2.0:../../devel/deforaos-coder
DEPENDS+=	deforaos-editor>=0.4.0:../../editors/deforaos-editor
DEPENDS+=	deforaos-icon-theme>=0.1.2:../../graphics/deforaos-icon-theme
DEPENDS+=	deforaos-integration>=0.0.2:../../x11/deforaos-integration
DEPENDS+=	deforaos-keyboard>=0.2.1:../../x11/deforaos-keyboard
DEPENDS+=	deforaos-locker>=0.4.0:../../x11/deforaos-locker
DEPENDS+=	deforaos-mailer>=0.1.7:../../mail/deforaos-mailer
DEPENDS+=	deforaos-mixer>=0.2.0:../../audio/deforaos-mixer
DEPENDS+=	deforaos-notes>=0.1.0:../../x11/deforaos-notes
DEPENDS+=	deforaos-panel>=0.3.6:../../x11/deforaos-panel
DEPENDS+=	deforaos-pdfviewer>=0.0.2:../../print/deforaos-pdfviewer
DEPENDS+=	deforaos-phone>=0.5.0:../../comms/deforaos-phone
DEPENDS+=	deforaos-player>=0.1.6:../../multimedia/deforaos-player
DEPENDS+=	deforaos-surfer>=0.2.10:../../www/deforaos-surfer
DEPENDS+=	deforaos-terminal>=0.0.0:../../sysutils/deforaos-terminal
DEPENDS+=	deforaos-todo>=0.2.1:../../time/deforaos-todo
DEPENDS+=	deforaos-vncviewer>=0.0.0:../../net/deforaos-vncviewer

MESSAGE_SUBST+=	BINDIR=${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
