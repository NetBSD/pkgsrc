# $NetBSD: Makefile,v 1.5 2009/07/14 22:05:39 joerg Exp $
#

DISTNAME=	embryo-0.9.9.061
CATEGORIES=	lang
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-06-14/
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
