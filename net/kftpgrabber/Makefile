# $NetBSD: Makefile,v 1.1.1.1 2005/02/09 13:06:53 markd Exp $

DISTNAME=	kftpgrabber-0.5.0
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kftpgrabber/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=       http://kftpgrabber.sourceforge.net/
COMMENT=	graphical FTP client for KDE

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
