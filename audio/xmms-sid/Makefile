# $NetBSD: Makefile,v 1.6 2003/07/17 21:24:17 grant Exp $
#

DISTNAME=	xmms-sid-0.7.4
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.tnsp.org/xs-files/

MAINTAINER=	mycroft@NetBSD.org
HOMEPAGE=	http://www.tnsp.org/
COMMENT=	XMMS plugin for SID (Commodore 64) music

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../audio/libsidplay/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
