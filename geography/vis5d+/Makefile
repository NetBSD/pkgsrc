# $NetBSD: Makefile,v 1.23 2020/03/20 11:57:46 nia Exp $
#

DISTNAME=		vis5d+-1.2.1
PKGREVISION=		5
CATEGORIES=		geography x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vis5d/}

MAINTAINER=		hdp@nmsu.edu
HOMEPAGE=		http://vis5d.sourceforge.net/
COMMENT=		Volumetric Visualization program for scientific datasets
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
