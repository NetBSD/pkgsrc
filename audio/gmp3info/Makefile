# $NetBSD: Makefile,v 1.2 2001/02/16 13:30:41 wiz Exp $

DISTNAME=	mp3info-0.8.2
PKGNAME=	g${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/linux/apps/sound/mp3-utils/mp3info/ \
		${MASTER_SITE_SUNSITE:=apps/sound/mp3-utils/mp3info/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.ibiblio.org/mp3info/
COMMENT=	Utility to read and modify the ID3 tags of MP3 files

DEPENDS+=	gtk+>=1.2.0:../../x11/gtk
DEPENDS+=	ncurses>=5.0:../../devel/ncurses

CONFLICTS=	mp3info-*

USE_X11=	YES

.include "../../mk/bsd.pkg.mk"
