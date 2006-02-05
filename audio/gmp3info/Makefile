# $NetBSD: Makefile,v 1.23 2006/02/05 23:08:08 joerg Exp $

DISTNAME=	mp3info-0.8.4
PKGNAME=	g${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/linux/apps/sound/mp3-utils/mp3info/ \
		${MASTER_SITE_SUNSITE:=apps/sound/mp3-utils/mp3info/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.ibiblio.org/mp3info/
COMMENT=	Utility to read and modify the ID3 tags of MP3 files

CONFLICTS=	mp3info-[0-9]*

# wgetnstr()
INCOMPAT_CURSES=	NetBSD-1.5-* NetBSD-1.5.*-* NetBSD-1.5[A-U]-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
