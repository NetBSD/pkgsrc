# $NetBSD: Makefile,v 1.1.1.1 2008/12/19 03:33:45 jmcneill Exp $
#

DISTNAME=	alsa-utils-1.0.18
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/utils/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.alsa-project.org/pub/utils/
COMMENT=	Advanced Linux Sound Architecture (ALSA) utilities

GNU_CONFIGURE=		yes
USE_TOOLS=		pkg-config gmake
USE_PKGLOCALEDIR=	yes
USE_NCURSES=		yes

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
