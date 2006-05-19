# $NetBSD: Makefile,v 1.13 2006/05/19 08:39:43 joerg Exp $
#

DISTNAME=		gopchop-1.1.7
PKGREVISION=		5
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gopchop/} \
			http://outflux.net/unix/software/GOPchop/download/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://outflux.net/unix/software/GOPchop/
COMMENT=		MPEG2 GOP-accurate editor

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
BROKEN_GETTEXT_DETECTION=	yes

.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
