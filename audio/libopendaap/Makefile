# $NetBSD: Makefile,v 1.1.1.1 2004/06/06 08:02:49 agc Exp $
#

DISTNAME=		libopendaap-0.2.1
CATEGORIES=		audio
MASTER_SITES=		http://crazney.net/programs/itunes/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://crazney.net/programs/itunes/libopendaap.html
COMMENT=		DAAP client library

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
