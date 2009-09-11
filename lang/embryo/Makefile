# $NetBSD: Makefile,v 1.6 2009/09/11 20:24:41 joerg Exp $
#

DISTNAME=	embryo-0.9.9.062
CATEGORIES=	lang
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-07-29/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	grzela@seculture.com
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Embeddable Scripting Language

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	embryo.pc.in

.include "../../mk/bsd.pkg.mk"
