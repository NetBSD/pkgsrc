# $NetBSD: Makefile,v 1.7 2012/10/23 19:51:13 asau Exp $
#

DISTNAME=		mesure-0.5
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nopcode.org/?t=mesure
COMMENT=		Tool to measure different kind of streams

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

NOT_FOR_PLATFORM+=	OpenBSD-*-*

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			DATADIR=${DESTDIR}${PREFIX}/share

.include "../../devel/gmp/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
