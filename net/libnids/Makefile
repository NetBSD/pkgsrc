# $NetBSD: Makefile,v 1.19 2005/04/05 22:13:29 adrianp Exp $
#

DISTNAME=	libnids-1.20
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libnids/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://libnids.sourceforge.net/
COMMENT=	Network monitoring library with TCP/IP reassembly

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

BUILDLINK_DEPMETHOD.libnet=	build
BUILDLINK_DEPMETHOD.libpcap=	build

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
