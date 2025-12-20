# $NetBSD: Makefile,v 1.8 2025/12/20 15:49:11 nia Exp $

DISTNAME=	daq-2.0.7
DIST_SUBDIR=	${DISTNAME}	# remove on next update
PKGREVISION=	1

CATEGORIES=	net security
MASTER_SITES=	https://snort.org/downloads/snort/

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://www.snort.org/
COMMENT=	Abstraction layer for libpcap
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

FORCE_C_STD=	gnu99

BUILDLINK_TRANSFORM+=	rm:-pedantic

CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t

.include "../../devel/flex/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
