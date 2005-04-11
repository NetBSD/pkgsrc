# $NetBSD: Makefile,v 1.2 2005/04/11 21:46:48 tv Exp $

DISTNAME=	kftpgrabber-0.5.0
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kftpgrabber/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=       http://kftpgrabber.sourceforge.net/
COMMENT=	graphical FTP client for KDE

BUILD_USES_MSGFMT=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
