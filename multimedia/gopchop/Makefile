# $NetBSD: Makefile,v 1.7 2005/08/15 02:15:56 wiz Exp $
#

DISTNAME=		gopchop-1.1.7
PKGREVISION=		1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gopchop/} \
			http://outflux.net/unix/software/GOPchop/download/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://outflux.net/unix/software/GOPchop/
COMMENT=		MPEG2 GOP-accurate editor

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
