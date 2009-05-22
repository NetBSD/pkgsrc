# $NetBSD: Makefile,v 1.3 2009/05/22 17:27:22 zafer Exp $
#

DISTNAME=		mesure-0.5
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nopcode.org/?t=mesure
COMMENT=		Tool to measure different kind of streams

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

NOT_FOR_PLATFORM+=	OpenBSD-*-*

.include "../../devel/gmp/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
