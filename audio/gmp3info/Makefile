# $NetBSD: Makefile,v 1.8 2001/10/24 22:10:43 jlam Exp $

DISTNAME=	mp3info-0.8.2
PKGNAME=	g${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/linux/apps/sound/mp3-utils/mp3info/ \
		${MASTER_SITE_SUNSITE:=apps/sound/mp3-utils/mp3info/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.ibiblio.org/mp3info/
COMMENT=	Utility to read and modify the ID3 tags of MP3 files

CONFLICTS=	mp3info-[0-9]*

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES

.include "../../mk/bsd.prefs.mk"

HAVE_WGETNSTR!=		${GREP} -cw wgetnstr /usr/include/curses.h || ${TRUE}

.if (${HAVE_WGETNSTR} == 0)
USE_NCURSES=		YES
.endif

.include "../../devel/ncurses/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
