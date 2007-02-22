# $NetBSD: Makefile,v 1.16 2007/02/22 19:01:14 wiz Exp $
#

DISTNAME=	xanalyser-1.24
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://arvin.schnell-web.net/xanalyser/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://arvin.schnell-web.net/xanalyser/
COMMENT=	Frequency spectrum analyser for X

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
