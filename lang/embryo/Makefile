# $NetBSD: Makefile,v 1.7 2009/12/16 19:30:31 joerg Exp $
#

DISTNAME=	embryo-0.9.9.063
CATEGORIES=	lang
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-12-02/
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
