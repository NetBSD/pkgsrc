# $NetBSD: Makefile,v 1.8 2013/02/06 19:31:05 jperkin Exp $
#

DISTNAME=		mesure-0.5
PKGREVISION=		3
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
