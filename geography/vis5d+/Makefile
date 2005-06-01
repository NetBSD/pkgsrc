# $NetBSD: Makefile,v 1.6 2005/06/01 18:02:53 jlam Exp $
#

DISTNAME=		vis5d+-1.2.1
PKGREVISION=		1
CATEGORIES=		geography x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vis5d/}

MAINTAINER=		hdp@nmsu.edu
HOMEPAGE=		http://vis5d.sourceforge.net/
COMMENT=		Volumetric Visualization program for scientific datasets

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=       yes

GNU_CONFIGURE=		yes

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
