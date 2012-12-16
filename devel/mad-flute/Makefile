# $NetBSD: Makefile,v 1.4 2012/12/16 01:52:11 obache Exp $

DISTNAME=		mad_fcl_v1.7_src
PKGNAME=		mad-flute-1.7
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://mad.cs.tut.fi/download/

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://mad.cs.tut.fi/
COMMENT=		Reliable Multicast Layering
LICENSE=		gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/flute ${DESTDIR}${PREFIX}/bin/flute
	${INSTALL_PROGRAM} ${WRKSRC}/bin/multis_flute ${DESTDIR}${PREFIX}/bin/multis_flute

.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
