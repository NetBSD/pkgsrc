# $NetBSD: Makefile,v 1.19 2011/12/09 14:36:33 drochner Exp $
#

DISTNAME=	xanalyser-1.24
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://arvin.schnell-web.net/xanalyser/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arvin.schnell-web.net/xanalyser/
COMMENT=	Frequency spectrum analyser for X

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
