# $NetBSD: Makefile,v 1.5 2008/06/21 18:35:03 adrianp Exp $
#

DISTNAME=	gpsbabel-1.3.4
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpsbabel/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.gpsbabel.org/
COMMENT=	Utility to convert and fetch GPS related data
#LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

LIBS.Darwin+=	-lexpat

GNU_CONFIGURE=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
