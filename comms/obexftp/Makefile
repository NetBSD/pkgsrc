# $NetBSD: Makefile,v 1.1.1.1 2004/02/26 12:50:43 jmmv Exp $
#

DISTNAME=	obexftp-0.10.3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://triq.net/obex/
COMMENT=	File copying over the Object Exchange (OBEX) protocol

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES

.include "../../comms/openobex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
