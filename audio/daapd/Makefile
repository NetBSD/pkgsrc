# $NetBSD: Makefile,v 1.1.1.1 2004/06/05 19:07:51 nathanw Exp $

DISTNAME=		daapd-0.2.2b
CATEGORIES=		audio
MASTER_SITES=		http://www.deleet.de/projekte/daap/daapd/
EXTRACT_SUFX=		.tgz

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.deleet.de/projekte/daap/daapd/
COMMENT=		Server for DAA protocol (iTunes)

USE_BUILDLINK3=		# defined
USE_GNU_TOOLS=		make
MAKEFILE=		makefile

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
