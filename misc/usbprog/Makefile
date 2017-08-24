# $NetBSD: Makefile,v 1.35 2017/08/24 20:03:32 adam Exp $
#

DISTNAME=	usbprog-0.2.0
PKGREVISION=	32
CATEGORIES=	misc
MASTER_SITES=	http://download.berlios.de/usbprog/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.embedded-projects.net/index.php?page_id=165
COMMENT=	Firmware loader for "usbprog" programming adapter
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
