# $NetBSD: Makefile,v 1.16 2010/07/30 10:36:24 asau Exp $
#

DISTNAME=		vis5d+-1.2.1
PKGREVISION=		3
CATEGORIES=		geography x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vis5d/}

MAINTAINER=		hdp@nmsu.edu
HOMEPAGE=		http://vis5d.sourceforge.net/
COMMENT=		Volumetric Visualization program for scientific datasets

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
