# $NetBSD: Makefile,v 1.3 2008/06/12 02:14:14 joerg Exp $
#

DISTNAME=	freealut-1.1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.openal.org/openal_webstf/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openal.org/
COMMENT=	OpenAL Utility Toolkit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	admin/pkgconfig/freealut.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
