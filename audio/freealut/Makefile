# $NetBSD: Makefile,v 1.7 2020/01/26 17:30:41 rillig Exp $
#

DISTNAME=	freealut-1.1.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.openal.org/openal_webstf/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openal.org/
COMMENT=	OpenAL Utility Toolkit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

REPLACE_SH=		admin/pkgconfig/freealut-config.in
PKGCONFIG_OVERRIDE+=	admin/pkgconfig/freealut.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
