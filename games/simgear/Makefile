# $NetBSD: Makefile,v 1.7 2009/06/30 00:07:16 joerg Exp $
#

DISTNAME=		SimGear-1.0.0
PKGNAME=		${DISTNAME:S/SimGear/simgear/}
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.de.simgear.org/pub/simgear/Source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.simgear.org/
COMMENT=		Simulator Construction Tools

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

.include "../../audio/openal/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.plib+= plib>=1.8.4
.include "../../games/plib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
