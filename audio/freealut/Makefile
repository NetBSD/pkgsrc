# $NetBSD: Makefile,v 1.1.1.1 2007/07/13 14:50:17 drochner Exp $
#

DISTNAME=	freealut-1.1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.openal.org/openal_webstf/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openal.org/
COMMENT=	OpenAL Utility Toolkit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	admin/pkgconfig/freealut.pc.in

.include "../../audio/openal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
