# $NetBSD: Makefile,v 1.2 2002/08/31 04:18:42 wiz Exp $
#

DISTNAME=	xmms-sid-0.7.2
CATEGORIES=	audio
MASTER_SITES=	http://www.tnsp.org/xs-files/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.tnsp.org/
COMMENT=	XMMS plugin for SID (Commodore 64) music

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../audio/libsidplay/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
