# $NetBSD: Makefile,v 1.1.1.1 2009/05/19 17:26:28 minskim Exp $
#

DISTNAME=	eina-0.0.2.060
CATEGORIES=	devel
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-04-22/
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
