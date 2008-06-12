# $NetBSD: Makefile,v 1.5 2008/06/12 02:14:15 joerg Exp $

DISTNAME=	WMmp-0.10.0
CATEGORIES=	audio
MASTER_SITES=	http://mercury.chem.pitt.edu/~shank/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicpd.org/WMmp.shtml
COMMENT=	Window Maker dock app for interfacing MPD

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
