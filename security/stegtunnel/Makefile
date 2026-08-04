# $NetBSD: Makefile,v 1.7 2026/08/04 20:29:14 wiz Exp $

DISTNAME=	stegtunnel-0.4
PKGREVISION=	1
CATEGORIES=	security
#MASTER_SITES=	http://www.synacklabs.net/projects/stegtunnel/

MAINTAINER=	agc@NetBSD.org
#HOMEPAGE=	http://www.synacklabs.net/projects/stegtunnel/
COMMENT=	Provides a covert channel in the IPID and sequence number

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

LIBS.SunOS+=	-lrt

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
