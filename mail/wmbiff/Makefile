# $NetBSD: Makefile,v 1.1.1.1 2001/05/29 05:45:40 tron Exp $

DISTNAME=	wmbiff-0.3.0
CATEGORIES=	mail x11
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=wmbiff/)

MAINTAINER=	magick@zhadum.de
COMMENT=	xbuffy like "mail-checker" for WindowMaker

DEPENDS+=	windowmaker-*:../../wm/windowmaker

USE_X11=	YES
USE_GMAKE=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}/wmbiff

.include "../../mk/bsd.pkg.mk"
