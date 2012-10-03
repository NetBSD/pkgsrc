# $NetBSD: Makefile,v 1.39.2.1 2012/10/03 12:06:31 spz Exp $

DISTNAME=	mp3info-0.8.5a
PKGNAME=	g${DISTNAME}
PKGREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/linux/apps/sound/mp3-utils/mp3info/ \
		${MASTER_SITE_SUNSITE:=apps/sound/mp3-utils/mp3info/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ibiblio.org/mp3info/
COMMENT=	Utility to read and modify the ID3 tags of MP3 files

CONFLICTS=	mp3info-[0-9]*

USE_TOOLS+=	pkg-config

# wgetnstr()
INCOMPAT_CURSES=	NetBSD-1.5-* NetBSD-1.5.*-* NetBSD-1.5[A-U]-*

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
