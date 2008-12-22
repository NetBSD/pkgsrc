# $NetBSD: Makefile,v 1.2 2008/12/22 03:18:12 jmcneill Exp $
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

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
