# $NetBSD: Makefile,v 1.8 2004/10/03 00:13:11 tv Exp $
#

DISTNAME=	xmms-sid-0.7.4
PKGREVISION=	3
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
