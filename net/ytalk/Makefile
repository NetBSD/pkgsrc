# $NetBSD: Makefile,v 1.3 1999/07/05 07:18:57 garbled Exp $

DISTNAME=       ytalk-3.1
CATEGORIES=	net
MASTER_SITES=   http://www.eleves.ens.fr:8080/home/espel/ytalk/\
		${MASTER_SITE_SUNSITE:=system/network/chat/}

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.eleves.ens.fr:8080/home/espel/ytalk/

GNU_CONFIGURE=	yes
LDFLAGS+= -Wl,-R${X11BASE}/lib

.include "../../mk/bsd.pkg.mk"
