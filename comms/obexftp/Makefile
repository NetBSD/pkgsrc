# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:16 tv Exp $
#

DISTNAME=	obexftp-0.10.3
PKGREVISION=	1
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
