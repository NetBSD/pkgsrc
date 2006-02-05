# $NetBSD: Makefile,v 1.10 2006/02/05 23:08:19 joerg Exp $
#

DISTNAME=	xmms-sid-0.7.4
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.tnsp.org/xs-files/

MAINTAINER=	mycroft@NetBSD.org
HOMEPAGE=	http://www.tnsp.org/
COMMENT=	XMMS plugin for SID (Commodore 64) music

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
