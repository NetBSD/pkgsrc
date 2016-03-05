# $NetBSD: Makefile,v 1.16 2016/03/05 11:28:36 jperkin Exp $
#

DISTNAME=	gpsbabel-1.5.2
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_LOCAL}
# Download from official site apparently only via interactive form,
# but code is gnu-gpl-v2 so hosted elsewhere.
# older versions were at
# MASTER_SITES+=	http://archlinux-stuff.googlecode.com/files/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gpsbabel.org/
COMMENT=	Utility to convert and fetch GPS related data
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

TEST_TARGET=	check

LIBS.Darwin+=	-lexpat

GNU_CONFIGURE=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
