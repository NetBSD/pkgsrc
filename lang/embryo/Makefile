# $NetBSD: Makefile,v 1.4 2009/06/07 14:42:54 joerg Exp $
#

DISTNAME=	embryo-0.9.9.060
CATEGORIES=	lang
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-04-22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	grzela@seculture.com
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Embeddable Scripting Language

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE=	embryo.pc.in

.include "../../mk/bsd.pkg.mk"
