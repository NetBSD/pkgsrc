# $NetBSD: Makefile,v 1.12 2006/05/28 15:16:10 joerg Exp $
#

DISTNAME=		vis5d+-1.2.1
PKGREVISION=		2
CATEGORIES=		geography x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vis5d/}

MAINTAINER=		hdp@nmsu.edu
HOMEPAGE=		http://vis5d.sourceforge.net/
COMMENT=		Volumetric Visualization program for scientific datasets

USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
