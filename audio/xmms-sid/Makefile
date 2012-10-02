# $NetBSD: Makefile,v 1.17 2012/10/02 23:48:16 asau Exp $
#

DISTNAME=	xmms-sid-0.7.4
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://www.tnsp.org/xs-files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tnsp.org/
COMMENT=	XMMS plugin for SID (Commodore 64) music

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
