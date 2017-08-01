# $NetBSD: Makefile,v 1.2 2017/08/01 14:59:03 wiz Exp $

DISTNAME=	daq-2.0.6
CATEGORIES=	net security
MASTER_SITES=	https://snort.org/downloads/snort/

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://www.snort.org/
COMMENT=	Abstraction layer for libpcap
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
.include "../../net/libdnet/buildlink3.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
