# $NetBSD: Makefile,v 1.2 2004/08/16 23:32:04 schmonz Exp $

DISTNAME=		daapd-0.2.2b
CATEGORIES=		audio
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tgz

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.deleet.de/projekte/daap/daapd/
COMMENT=		Server for DAA protocol (iTunes)

USE_LANGUAGES=		c c++
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
MAKEFILE=		makefile

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
