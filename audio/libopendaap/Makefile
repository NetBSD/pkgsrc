# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:07 tv Exp $
#

DISTNAME=		libopendaap-0.2.1
PKGREVISION=		1
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
