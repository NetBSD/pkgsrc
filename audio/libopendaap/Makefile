# $NetBSD: Makefile,v 1.3 2005/03/07 15:30:44 adam Exp $

DISTNAME=	libopendaap-0.3.0
CATEGORIES=	audio
MASTER_SITES=	http://crazney.net/programs/itunes/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://crazney.net/programs/itunes/libopendaap.html
COMMENT=	DAAP client library

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
