# $NetBSD: Makefile,v 1.1.1.1 2012/05/02 04:43:11 agc Exp $

DISTNAME=		mad_fcl_v1.7_src
PKGNAME=		mad-flute-1.7
CATEGORIES=		devel
MASTER_SITES=		http://mad.cs.tut.fi/download/

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://mad.cs.tut.fi/
COMMENT=		Reliable Multicast Layering
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/flute ${DESTDIR}${PREFIX}/bin/flute
	${INSTALL_PROGRAM} ${WRKSRC}/bin/multis_flute ${DESTDIR}${PREFIX}/bin/multis_flute

.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
