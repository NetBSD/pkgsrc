# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:35 joerg Exp $

DISTNAME=	stegtunnel-0.4
CATEGORIES=	security
MASTER_SITES=	http://www.synacklabs.net/projects/stegtunnel/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.synacklabs.net/projects/stegtunnel/
COMMENT=	Provides a covert channel in the IPID and sequence number

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
