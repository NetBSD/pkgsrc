# $NetBSD: Makefile,v 1.1.1.1 2001/02/15 09:26:01 tron Exp $

DISTNAME=	mp3info-0.8.2
PKGNAME=	g${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/linux/apps/sound/mp3-utils/mp3info/ \
		${MASTER_SITE_SUNSITE:=apps/sound/mp3-utils/mp3info/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.ibiblio.org/mp3info/

DEPENDS+=	gtk+>=1.2.0:../../x11/gtk
DEPENDS+=	ncurses>=5.0:../../devel/ncurses

CONFLICTS=	mp3info-*

USE_X11=	YES

.include "../../mk/bsd.pkg.mk"
