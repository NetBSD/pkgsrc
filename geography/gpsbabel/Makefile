# $NetBSD: Makefile,v 1.42 2022/07/02 16:53:21 ryoon Exp $
#

DISTNAME=	gpsbabel-1.6.0
PKGREVISION=	18
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_BACKUP}
# Download from official site apparently only via interactive form,
# but code is gnu-gpl-v2 so hosted elsewhere.
# older versions were at
# MASTER_SITES+=	http://archlinux-stuff.googlecode.com/files/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.gpsbabel.org/
#HOMEPAGE=	https://github.com/gpsbabel/gpsbabel
COMMENT=	Utility to convert and fetch GPS related data
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++11
USE_TOOLS=	gmake

TEST_TARGET=	check

# \todo Upstream recommends trying qmake.
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	QMAKE=${QTDIR}/bin/qmake
CONFIGURE_ENV+=	LUPDATE=${QTDIR}/bin/lupdate
CONFIGURE_ENV+=	LRELEASE=${QTDIR}/bin/lrelease

# \todo This seems like a bug; explain why.
LIBS.Darwin+=	-lexpat

# \todo Figure out stdarg warnings for code that looks correct.
# util.cc: In function 'int xasprintf(char**, const char*, ...)':
# util.cc:233:22: warning: second parameter of 'va_start' not last named argument [-Wvarargs]
#    va_start(args, fmt);
#                       ^

# gpsbabel 1.6.0 really does need libusb 0.1, and uses usb_interrupt_read
.include "../../mk/libusb.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
