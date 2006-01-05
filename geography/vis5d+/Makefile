# $NetBSD: Makefile,v 1.7 2006/01/05 00:00:09 joerg Exp $
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
BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
