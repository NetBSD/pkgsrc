# $NetBSD: Makefile,v 1.18 2007/05/05 21:39:11 markd Exp $

DISTNAME=	kftpgrabber-0.8.1
CATEGORIES=	net kde
MASTER_SITES=	http://www.kftp.org/uploads/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.kftp.org/
COMMENT=	Graphical FTP client for KDE

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgfmt perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
