# $NetBSD: Makefile,v 1.4 2001/09/27 23:18:23 jlam Exp $

DISTNAME=	wmbiff-0.3.1
CATEGORIES=	mail x11
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=wmbiff/)

MAINTAINER=	magick@zhadum.de
HOMEPAGE=	http://sourceforge.net/projects/wmbiff/
COMMENT=	xbuffy like "mail-checker" for WindowMaker

DEPENDS+=	windowmaker-[0-9]*:../../wm/windowmaker

USE_X11=	YES
USE_XPM=	YES
USE_GMAKE=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}/wmbiff

.include "../../mk/bsd.pkg.mk"
