# $NetBSD: Makefile,v 1.13 2020/01/31 02:13:52 khorben Exp $
#

DISTNAME=	deforaos-desktop-2020.1.0
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	Meta-package for the DeforaOS Desktop environment
LICENSE=	gnu-gpl-v3

META_PACKAGE=	yes

DEPENDS+=	deforaos-browser>=0.5.3:../../sysutils/deforaos-browser
DEPENDS+=	deforaos-camera>=0.3.0:../../graphics/deforaos-camera
DEPENDS+=	deforaos-coder>=0.3.0:../../devel/deforaos-coder
DEPENDS+=	deforaos-editor>=0.4.1:../../editors/deforaos-editor
DEPENDS+=	deforaos-icon-theme>=0.1.3:../../graphics/deforaos-icon-theme
DEPENDS+=	deforaos-integration>=0.1.0:../../x11/deforaos-integration
DEPENDS+=	deforaos-keyboard>=0.4.0:../../x11/deforaos-keyboard
DEPENDS+=	deforaos-locker>=0.4.1:../../x11/deforaos-locker
DEPENDS+=	deforaos-mailer>=0.2.0:../../mail/deforaos-mailer
DEPENDS+=	deforaos-mixer>=0.4.0:../../audio/deforaos-mixer
DEPENDS+=	deforaos-notes>=0.2.0:../../x11/deforaos-notes
DEPENDS+=	deforaos-panel>=0.4.0:../../x11/deforaos-panel
DEPENDS+=	deforaos-pdfviewer>=0.1.0:../../print/deforaos-pdfviewer
DEPENDS+=	deforaos-phone>=0.6.0:../../comms/deforaos-phone
DEPENDS+=	deforaos-player>=0.2.0:../../multimedia/deforaos-player
DEPENDS+=	deforaos-surfer>=0.3.0:../../www/deforaos-surfer
DEPENDS+=	deforaos-terminal>=0.2.0:../../sysutils/deforaos-terminal
DEPENDS+=	deforaos-todo>=0.3.0:../../time/deforaos-todo
DEPENDS+=	deforaos-vncviewer>=0.1.0:../../net/deforaos-vncviewer

MESSAGE_SUBST+=	BINDIR=${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
