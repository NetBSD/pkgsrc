# $NetBSD: Makefile,v 1.1.1.1 2003/10/05 16:43:08 jschauma Exp $
#

DISTNAME=		vis5d+-1.2.1
CATEGORIES=		geography x11
MASTER_SITES=		http://easynews.dl.sourceforge.net/sourceforge/vis5d/

MAINTAINER=		hdp@nmsu.edu
HOMEPAGE=		http://vis5d.sourceforge.net/
COMMENT=		Volumetric Visualization program for scientific datasets

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=       yes
USE_X11=		yes

GNU_CONFIGURE=		yes

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
