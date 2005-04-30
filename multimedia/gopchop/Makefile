# $NetBSD: Makefile,v 1.4 2005/04/30 23:06:25 wiz Exp $
#

DISTNAME=		gopchop-1.1.6
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gopchop/} \
			http://outflux.net/unix/software/GOPchop/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://outflux.net/unix/software/GOPchop/
COMMENT=		MPEG2 GOP-accurate editor

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1

.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
