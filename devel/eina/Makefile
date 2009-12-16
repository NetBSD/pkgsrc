# $NetBSD: Makefile,v 1.4 2009/12/16 19:52:58 joerg Exp $
#

DISTNAME=	eina-0.9.9.063
CATEGORIES=	devel
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-12-02/
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
