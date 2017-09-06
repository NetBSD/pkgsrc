# $NetBSD: Makefile,v 1.10 2017/09/06 10:40:25 wiz Exp $

DISTNAME=	WMmp-0.10.0
CATEGORIES=	audio
MASTER_SITES=	# http://mercury.chem.pitt.edu/~shank/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://musicpd.org/WMmp.shtml
COMMENT=	Window Maker dock app for interfacing MPD
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
