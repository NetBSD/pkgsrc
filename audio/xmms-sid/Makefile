# $NetBSD: Makefile,v 1.19 2016/04/20 12:10:35 nros Exp $
#

DISTNAME=	xmms-sid-0.7.4
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://www.tnsp.org/xs-files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tnsp.org/
COMMENT=	XMMS plugin for SID (Commodore 64) music
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

.include "../../audio/libsidplay/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
