# $NetBSD: Makefile,v 1.1.1.1 2015/07/22 19:05:10 asau Exp $

PKGNAME=	gabedit-2.4.8
DISTNAME=	GabeditSrc248
CATEGORIES=	biology
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=gabedit/)

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://gabedit.sourceforge.net/
COMMENT=	A Graphical User Interface to computational chemistry packages

USE_TOOLS=	gmake pkg-config

INSTALLATION_DIRS=	bin

do-configure:
	cd $(WRKSRC) && cp platforms/CONFIG.unix CONFIG

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/gabedit $(DESTDIR)$(PREFIX)/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
