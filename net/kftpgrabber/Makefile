# $NetBSD: Makefile,v 1.4 2005/10/08 10:55:05 markd Exp $

DISTNAME=	kftpgrabber-0.6.0
CATEGORIES=	net kde
MASTER_SITES=	http://kftpgrabber.sourceforge.net/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=       http://kftpgrabber.sourceforge.net/
COMMENT=	graphical FTP client for KDE

BUILD_USES_MSGFMT=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# a fix for qt-3.3.5, please remove if qt-3.3.6 (or newer) solves the problem
SUBST_CLASSES+=		hints
SUBST_STAGE.hints=	post-patch
SUBST_MESSAGE.hints=	"Fix includehints."
SUBST_FILES.hints=	kftpgrabber/src/ui/kftpqueueeditorlayout.ui \
			kftpgrabber/src/ui/kftpsearchlayout.ui
SUBST_FILTER_CMD.hints=	${GREP} -v includehint

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
