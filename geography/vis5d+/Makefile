# $NetBSD: Makefile,v 1.4 2004/10/03 00:14:47 tv Exp $
#

DISTNAME=		vis5d+-1.2.1
PKGREVISION=		1
CATEGORIES=		geography x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vis5d/}

MAINTAINER=		hdp@nmsu.edu
HOMEPAGE=		http://vis5d.sourceforge.net/
COMMENT=		Volumetric Visualization program for scientific datasets

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=       yes
USE_X11=		yes

GNU_CONFIGURE=		yes

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
