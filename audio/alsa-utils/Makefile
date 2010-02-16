# $NetBSD: Makefile,v 1.6 2010/02/16 18:28:01 wiz Exp $
#

DISTNAME=	alsa-utils-1.0.22
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/utils/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.alsa-project.org/pub/utils/
COMMENT=	Advanced Linux Sound Architecture (ALSA) utilities

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS=		pkg-config gmake bash:run
USE_PKGLOCALEDIR=	yes
USE_NCURSES=		yes

REPLACE_BASH=		alsaconf/alsaconf.in

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
