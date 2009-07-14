# $NetBSD: Makefile,v 1.2 2009/07/14 22:05:10 joerg Exp $
#

DISTNAME=	eina-0.0.2.061
CATEGORIES=	devel
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-06-14/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Data types library

LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	eina-0.pc.in

.include "../../mk/bsd.pkg.mk"
