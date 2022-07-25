# $NetBSD: Makefile,v 1.6 2022/07/25 11:12:26 wiz Exp $

DISTNAME=	libnms-0.6.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.paldo.org/paldo/sources/libnms/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
#HOMEPAGE=	http://streaming.polito.it/client/library/
COMMENT=	Open Media Streaming Client Library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libnms.pc.in

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
