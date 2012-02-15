# $NetBSD: Makefile,v 1.4 2012/02/15 21:25:52 hans Exp $
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

REPLACE_SH=		admin/pkgconfig/freealut-config.in
PKGCONFIG_OVERRIDE+=	admin/pkgconfig/freealut.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
