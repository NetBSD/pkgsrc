# $NetBSD: Makefile,v 1.12 2018/08/22 09:45:48 wiz Exp $
#

PKGNAME=	dvb-apps-20110713
PKGREVISION=	7
DISTNAME=	148ede2a6809
DIST_SUBDIR=	dvb-apps
CATEGORIES=	multimedia
MASTER_SITES=	https://linuxtv.org/hg/dvb-apps/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://linuxtv.org/
COMMENT=	Digital Video Broadcasting (DVB) applications

# netbsd-5 does not have dev/dtv/dtvio.h or its associated functionality.
# (allow 5.99.* as relatively recent 5.99 may still be in use and should work)
NOT_FOR_PLATFORM+=	NetBSD-5.[0-8]*

USE_TOOLS+=	gmake perl

WRKSRC=	${WRKDIR}/dvb-apps-148ede2a6809

do-build:
	cd ${WRKSRC}/lib/libdvbapi && gmake prefix=${PREFIX}
	cd ${WRKSRC}/lib/libucsi && gmake prefix=${PREFIX}
	cd ${WRKSRC}/util/atsc_epg&& gmake prefix=${PREFIX}
	cd ${WRKSRC}/util/dvbdate && gmake prefix=${PREFIX}
	cd ${WRKSRC}/util/scan && gmake prefix=${PREFIX}
	cd ${WRKSRC}/util/szap && gmake prefix=${PREFIX}

do-install:
	cd ${WRKSRC}/lib/libdvbapi && \
		gmake DESTDIR=${DESTDIR} prefix=${PREFIX} install
	cd ${WRKSRC}/lib/libucsi && \
		gmake DESTDIR=${DESTDIR} prefix=${PREFIX} install
	cd ${WRKSRC}/util/atsc_epg && \
		gmake DESTDIR=${DESTDIR} prefix=${PREFIX} install
	cd ${WRKSRC}/util/dvbdate && \
		gmake DESTDIR=${DESTDIR} prefix=${PREFIX} install
	cd ${WRKSRC}/util/scan && \
		gmake DESTDIR=${DESTDIR} prefix=${PREFIX} install
	cd ${WRKSRC}/util/szap && \
		gmake DESTDIR=${DESTDIR} prefix=${PREFIX} install

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
