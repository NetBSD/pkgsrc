# $NetBSD: Makefile,v 1.5 2005/04/11 21:44:54 tv Exp $

DISTNAME=	libopendaap-0.3.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://crazney.net/programs/itunes/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://crazney.net/programs/itunes/libopendaap.html
COMMENT=	DAAP client library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/pkgconfig/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
