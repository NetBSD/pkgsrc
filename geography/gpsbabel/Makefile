# $NetBSD: Makefile,v 1.11 2011/04/27 18:57:11 schwarz Exp $
#

DISTNAME=	gpsbabel-1.4.2
CATEGORIES=	geography
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpsbabel/}
# Download from official site apparently only via interactive form,
# but code is gnu-gpl-v2 so hosted elsewhere as a convenience to
# pkgsrc users.
MASTER_SITES+=	http://www.lexort.com/pkgsrc/distfiles/
MASTER_SITES+=	http://archlinux-stuff.googlecode.com/files/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.gpsbabel.org/
COMMENT=	Utility to convert and fetch GPS related data
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

LIBS.Darwin+=	-lexpat

GNU_CONFIGURE=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
