# $NetBSD: Makefile,v 1.7 2004/03/12 04:28:12 snj Exp $
#

DISTNAME=	xmms-sid-0.7.4
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.tnsp.org/xs-files/

MAINTAINER=	mycroft@NetBSD.org
HOMEPAGE=	http://www.tnsp.org/
COMMENT=	XMMS plugin for SID (Commodore 64) music

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
