# $NetBSD: Makefile,v 1.27 2020/04/12 08:28:46 adam Exp $
#

DISTNAME=	gpsbabel-1.6.0
PKGREVISION=	5
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_LOCAL}
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

.include "../../mk/libusb.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
