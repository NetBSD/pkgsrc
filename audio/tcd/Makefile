# $NetBSD: Makefile,v 1.17 2024/05/06 08:40:21 jperkin Exp $
#

DISTNAME=		tcd-2.2.0
PKGREVISION=		7
CATEGORIES=		audio
MASTER_SITES=		https://download.savannah.gnu.org/releases/tcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.nongnu.org/tcd/
COMMENT=		Audio CD player using ncurses and SDL
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
