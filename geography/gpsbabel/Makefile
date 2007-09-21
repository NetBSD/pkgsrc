# $NetBSD: Makefile,v 1.1.1.1 2007/09/21 05:12:08 martti Exp $
#

DISTNAME=	gpsbabel-1.3.4
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpsbabel/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.gpsbabel.org/
COMMENT=	Utility to convert and fetch GPS related data

GNU_CONFIGURE=	yes

.include "../../devel/libusb/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
