# $NetBSD: Makefile,v 1.3 2008/11/29 17:55:38 joerg Exp $
#

DISTNAME=	embryo-0.9.9.050
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-09-25/
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
