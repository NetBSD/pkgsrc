# $NetBSD: Makefile,v 1.3 2001/07/11 16:49:02 magick Exp $

DISTNAME=	wmbiff-0.3.1
CATEGORIES=	mail x11
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=wmbiff/)

MAINTAINER=	magick@zhadum.de
HOMEPAGE=	http://sourceforge.net/projects/wmbiff/
COMMENT=	xbuffy like "mail-checker" for WindowMaker

DEPENDS+=	windowmaker-*:../../wm/windowmaker

USE_X11=	YES
USE_XPM=	YES
USE_GMAKE=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}/wmbiff

.include "../../mk/bsd.pkg.mk"
