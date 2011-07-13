# $NetBSD: Makefile,v 1.1.1.1 2011/07/13 23:42:16 jmcneill Exp $
#

PKGNAME=	dvb-apps-20110713
DISTNAME=	148ede2a6809
DIST_SUBDIR=	dvb-apps
CATEGORIES=	multimedia
MASTER_SITES=	http://linuxtv.org/hg/dvb-apps/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linuxtv.org/
COMMENT=	Digital Video Broadcasting (DVB) applications

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake perl

WRKSRC=	${WRKDIR}/dvb-apps-148ede2a6809

do-build:
	cd ${WRKSRC}/util/scan && gmake

do-install:
	cd ${WRKSRC}/util/scan && \
		gmake DESTDIR=${DESTDIR} prefix=${PREFIX} install

.include "../../mk/bsd.pkg.mk"
