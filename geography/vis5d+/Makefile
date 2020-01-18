# $NetBSD: Makefile,v 1.22 2020/01/18 23:32:09 rillig Exp $
#

DISTNAME=		vis5d+-1.2.1
PKGREVISION=		5
CATEGORIES=		geography x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vis5d/}

MAINTAINER=		hdp@nmsu.edu
HOMEPAGE=		https://vis5d.sourceforge.net/
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
